#ifndef REQUESTSWIDGET_H
#define REQUESTSWIDGET_H

#include <QWidget>
#include <QSqlTableModel> // Добавлено
#include "../common/services/AuthService.h"

namespace Ui {
    class RequestsWidget;
}

class RequestsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RequestsWidget(QWidget *parent = nullptr);
    ~RequestsWidget();

signals:
    void logoutRequested();

private slots:
    void updateRequests();

private:
    Ui::RequestsWidget *ui;
    AuthService *authService;
    QSqlTableModel *model; // Теперь с объявленным типом
};

#endif // REQUESTSWIDGET_H
