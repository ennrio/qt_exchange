#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "../common/services/AuthService.h"

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    bool isAuthenticated() const;
    QString username() const;

private slots:
    void onLoginClicked();

private:
    Ui::LoginDialog *ui;
    AuthService *authService;
    bool authenticated;
};

#endif // LOGINDIALOG_H
