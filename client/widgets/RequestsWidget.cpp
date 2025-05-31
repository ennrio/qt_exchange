#include "RequestsWidget.h"
#include "ui_RequestsWidget.h"
#include "../common/database/DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>

RequestsWidget::RequestsWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::RequestsWidget),
authService(new AuthService(this)),
model(new QSqlTableModel(this))
{
    ui->setupUi(this);

    model->setTable("exchange_requests");
    model->setFilter(QString("user_id = %1").arg(authService->userId()));
    model->setHeaderData(2, Qt::Horizontal, "From Currency");
    model->setHeaderData(3, Qt::Horizontal, "To Currency");
    model->setHeaderData(4, Qt::Horizontal, "Amount");
    model->setHeaderData(5, Qt::Horizontal, "Status");
    model->setHeaderData(8, Qt::Horizontal, "Admin Notes");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0); // ID
    ui->tableView->hideColumn(1); // user_id
    ui->tableView->resizeColumnsToContents();

    connect(ui->refreshButton, &QPushButton::clicked, this, &RequestsWidget::updateRequests);
}

RequestsWidget::~RequestsWidget()
{
    delete ui;
}

void RequestsWidget::updateRequests()
{
    model->setFilter(QString("user_id = %1").arg(authService->userId()));
    model->select();
    ui->tableView->resizeColumnsToContents();
}
