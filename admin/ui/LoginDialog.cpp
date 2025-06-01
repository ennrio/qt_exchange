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
    setWindowTitle("Admin Login");

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

    if (authService->login(username, password) && authService->isAdmin()) {
        authenticated = true;
        accept();
    } else {
        QMessageBox::warning(this, "Error", "Invalid admin credentials");
    }
}

bool LoginDialog::isAdminAuthenticated() const
{
    return authenticated;
}
