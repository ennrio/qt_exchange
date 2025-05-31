#include "ProfileWidget.h"
#include "ui_ProfileWidget.h"
#include "../common/database/DatabaseManager.h"
#include <QMessageBox>
#include <QCryptographicHash>

ProfileWidget::ProfileWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::ProfileWidget),
authService(new AuthService(this))
{
    ui->setupUi(this);

    // Скрываем поля пароля до нажатия кнопки изменения
    ui->passwordGroup->setVisible(false);

    connect(ui->changePasswordButton, &QPushButton::clicked,
            this, &ProfileWidget::onPasswordChangeClicked);
    connect(ui->savePasswordButton, &QPushButton::clicked,
            this, &ProfileWidget::onPasswordChangeClicked);
    connect(ui->logoutButton, &QPushButton::clicked,
            this, &ProfileWidget::onLogoutClicked);

    updateUserInfo();
}

ProfileWidget::~ProfileWidget()
{
    delete ui;
}

void ProfileWidget::updateUserInfo()
{
    if (authService->isAuthenticated()) {
        ui->usernameLabel->setText("Username: " + authService->username());
        ui->usernameLabel->setText(authService->username());
        ui->fullNameLabel->setText(authService->fullName());
        ui->roleLabel->setText(authService->isAdmin() ? "Administrator" : "User");
    } else {
        ui->usernameLabel->setText("Not authenticated");
        ui->fullNameLabel->setText("");
        ui->roleLabel->setText("");
    }
}

void ProfileWidget::onPasswordChangeClicked()
{
    if (!ui->passwordGroup->isVisible()) {
        ui->passwordGroup->setVisible(true);
        ui->changePasswordButton->setText("Cancel");
        return;
    }

    // Проверка совпадения паролей
    if (ui->newPassword->text() != ui->confirmPassword->text()) {
        QMessageBox::warning(this, "Error", "Passwords do not match!");
        return;
    }
}

void ProfileWidget::onLogoutClicked()
{
    authService->logout();
    emit logoutRequested();
}
