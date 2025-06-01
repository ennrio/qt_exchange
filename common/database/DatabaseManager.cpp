#include "DatabaseManager.h"
#include <QFile>
#include <QDebug>
#include <QDateTime>

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

bool DatabaseManager::initialize(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qCritical() << "Cannot open database:" << db.lastError().text();
        return false;
    }

    // Создание таблиц
    QSqlQuery query;
    bool success = query.exec("PRAGMA foreign_keys = ON;");

    success = success && query.exec(R"(
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username VARCHAR(50) UNIQUE NOT NULL,
            password_hash VARCHAR(128) NOT NULL,
            full_name VARCHAR(100),
            role VARCHAR(20) DEFAULT 'user' CHECK(role IN ('user', 'admin')),
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )");

    success = success && query.exec(R"(
        CREATE TABLE IF NOT EXISTS currencies (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            code VARCHAR(3) UNIQUE NOT NULL,
            name VARCHAR(50) NOT NULL,
            rate REAL NOT NULL,
            last_updated TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )");

    success = success && query.exec(R"(
        CREATE TABLE IF NOT EXISTS exchange_requests (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL REFERENCES users(id) ON DELETE CASCADE,
            from_currency_id INTEGER NOT NULL REFERENCES currencies(id),
            to_currency_id INTEGER NOT NULL REFERENCES currencies(id),
            amount REAL NOT NULL,
            status VARCHAR(20) DEFAULT 'pending' CHECK(status IN ('pending', 'approved', 'rejected')),
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            processed_at TIMESTAMP,
            admin_notes TEXT
        )
    )");

    // Проверка существования администратора
    query.exec("SELECT COUNT(*) FROM users WHERE role='admin'");
    if (query.next() && query.value(0).toInt() == 0) {
        addUser("admin", "password", "Administrator", "admin");
    }

    // Проверка существования валют
    query.exec("SELECT COUNT(*) FROM currencies");
    if (query.next() && query.value(0).toInt() == 0) {
        query.exec("INSERT INTO currencies (code, name, rate) VALUES "
                   "('USD', 'US Dollar', 1.0),"
                   "('EUR', 'Euro', 0.93),"
                   "('GBP', 'British Pound', 0.79),"
                   "('JPY', 'Japanese Yen', 151.86),"
                   "('CAD', 'Canadian Dollar', 1.36)");
    }

    return success;
}

QString DatabaseManager::hashPassword(const QString &password) const
{
    return QCryptographicHash::hash(
               (password + "secure_salt_value").toUtf8(),
               QCryptographicHash::Sha256
               ).toHex();
}

bool DatabaseManager::addUser(const QString& username, const QString& password,
                              const QString& fullName, const QString& role)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash, full_name, role) "
                  "VALUES (?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue(hashPassword(password));
    query.addBindValue(fullName);
    query.addBindValue(role);
    return query.exec();
}

QVariantMap DatabaseManager::authenticateUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT id, password_hash, role, full_name FROM users WHERE username = ?");
    query.addBindValue(username);

    if (query.exec() && query.next()) {
        QString storedHash = query.value("password_hash").toString();
        QString inputHash = hashPassword(password);

        if (storedHash == inputHash) {
            return {
                {"id", query.value("id")},
                {"role", query.value("role")},
                {"full_name", query.value("full_name")},
                {"authenticated", true}
            };
        }
    }
    return {{"authenticated", false}};
}

QString DatabaseManager::getUsername(int userId) const
{
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE id = ?");
    query.addBindValue(userId);

    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return "";
}

QList<QVariantMap> DatabaseManager::getAllCurrencies()
{
    QList<QVariantMap> currencies;
    QSqlQuery query("SELECT id, code, name, rate FROM currencies");

    while (query.next()) {
        QVariantMap currency;
        currency["id"] = query.value("id");
        currency["code"] = query.value("code");
        currency["name"] = query.value("name");
        currency["rate"] = query.value("rate");
        currencies.append(currency);
    }

    return currencies;
}

int DatabaseManager::createExchangeRequest(int userId, int fromCurrencyId, int toCurrencyId, double amount)
{
    QSqlQuery query;
    query.prepare("INSERT INTO exchange_requests (user_id, from_currency_id, to_currency_id, amount) "
    "VALUES (?, ?, ?, ?)");
    query.addBindValue(userId);
    query.addBindValue(fromCurrencyId);
    query.addBindValue(toCurrencyId);
    query.addBindValue(amount);

    if (query.exec()) {
        return query.lastInsertId().toInt();
    } else {
        qCritical() << "Failed to create exchange request:" << query.lastError().text();
        return -1;
    }
}

bool DatabaseManager::updateRequestStatus(int requestId, const QString& status, const QString& adminNotes)
{
    QSqlQuery query;
    query.prepare("UPDATE exchange_requests SET status = ?, admin_notes = ?, processed_at = CURRENT_TIMESTAMP "
                  "WHERE id = ?");
    query.addBindValue(status);
    query.addBindValue(adminNotes);
    query.addBindValue(requestId);

    if (query.exec()) {
        return true;
    } else {
        qCritical() << "Failed to update request status:" << query.lastError().text();
        return false;
    }
}
