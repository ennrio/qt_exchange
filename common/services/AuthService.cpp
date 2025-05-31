#include "AuthService.h"
//#include "common/database/DatabaseManager.h"
#include "../common/database/DatabaseManager.h"

AuthService::AuthService(QObject *parent) : QObject(parent) {}

bool AuthService::login(const QString &username, const QString &password)
{
    auto result = DatabaseManager::instance().authenticateUser(username, password);
    if (result["authenticated"].toBool()) {
        m_userId = result["id"].toInt();
        m_username = username; // Сохраняем имя пользователя
        m_fullName = result["full_name"].toString();
        m_role = result["role"].toString();
        emit authStateChanged(true);
        return true;
    }
    return false;
}

void AuthService::logout()
{
    m_userId = -1;
    m_username = "";
    m_fullName = "";
    m_role = "";
    emit authStateChanged(false);
}

bool AuthService::isAuthenticated() const { return m_userId != -1; }
bool AuthService::isAdmin() const { return m_role == "admin"; }
QString AuthService::fullName() const { return m_fullName; }
QString AuthService::username() const { return m_username; }
int AuthService::userId() const { return m_userId; }
