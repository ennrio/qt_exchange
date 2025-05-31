#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include <QObject>
#include <QString>

class AuthService : public QObject
{
    Q_OBJECT
public:
    explicit AuthService(QObject *parent = nullptr);

    bool login(const QString &username, const QString &password);
    void logout();
    bool isAuthenticated() const;
    bool isAdmin() const;
    QString fullName() const;
    QString username() const; // Единственное объявление
    int userId() const;

signals:
    void authStateChanged(bool authenticated);

private:
    int m_userId = -1;
    QString m_username;
    QString m_fullName;
    QString m_role;
};

#endif // AUTHSERVICE_H
