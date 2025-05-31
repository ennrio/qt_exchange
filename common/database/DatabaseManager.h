#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QList>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QVariantMap>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager& instance();
    bool initialize(const QString& path = "exchange.db");
    QSqlDatabase database() const;

    bool addUser(const QString& username, const QString& password,
                 const QString& fullName, const QString& role = "user");
    QVariantMap authenticateUser(const QString& username, const QString& password);
    QList<QVariantMap> getAllCurrencies();
    bool updateCurrencyRate(int currencyId, double rate);
    int createExchangeRequest(int userId, int fromCurrencyId,
                              int toCurrencyId, double amount);
    bool updateRequestStatus(int requestId, const QString& status,
                             const QString& adminNotes = "");
    QList<QVariantMap> getUserRequests(int userId);
    QList<QVariantMap> getAllRequests();
    QList<QVariantMap> getAllUsers();
    QString getUsername(int userId) const;

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    QString hashPassword(const QString &password) const;

    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
