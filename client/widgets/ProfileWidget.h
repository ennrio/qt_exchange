#ifndef PROFILEWIDGET_H
#define PROFILEWIDGET_H

#include <QWidget>
#include "../common/services/AuthService.h"

namespace Ui {
    class ProfileWidget;
}

class ProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileWidget(QWidget *parent = nullptr);
    ~ProfileWidget();

private slots:
    void onPasswordChangeClicked();
    void onLogoutClicked();

private:
    void updateUserInfo();

    Ui::ProfileWidget *ui;
    AuthService *authService;
};

#endif // PROFILEWIDGET_H
