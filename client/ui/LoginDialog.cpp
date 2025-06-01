#include "LoginDialog.h"
#include "ui_LoginDialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
QDialog(parent),
ui(new Ui::LoginDialog),
authService(new AuthService(this)),
authenticated(false)
{
    ui->setupUi(this);
    setWindowTitle("Login");

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::onLoginClicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (authService->login(username, password)) {
        authenticated = true;
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Invalid username or password");
    }
}

bool LoginDialog::isAuthenticated() const
{
    return authenticated;
}

QString LoginDialog::username() const
{
    return authService->username();
}
