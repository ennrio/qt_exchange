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

public slots:
    void updateRequests();

private slots:
    void onApproveClicked();
    void onRejectClicked();

private:
    Ui::RequestsAdminWidget *ui;
    QSqlRelationalTableModel *model;
};

#endif // REQUESTSADMINWIDGET_H
