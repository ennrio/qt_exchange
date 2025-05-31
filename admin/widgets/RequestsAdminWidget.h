#ifndef REQUESTSADMINWIDGET_H
#define REQUESTSADMINWIDGET_H

#include <QWidget>
#include <QSqlRelationalTableModel>

namespace Ui {
    class RequestsAdminWidget;
}

class RequestsAdminWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RequestsAdminWidget(QWidget *parent = nullptr);
    ~RequestsAdminWidget();

private slots:
    void onApproveClicked();
    void onRejectClicked();
    void updateRequests();

private:
    Ui::RequestsAdminWidget *ui;
    QSqlRelationalTableModel *model;
};

#endif // REQUESTSADMINWIDGET_H
