#include <QInputDialog>
#include <QSqlRelationalTableModel> /
#include "RequestsAdminWidget.h"
#include "ui_RequestsAdminWidget.h"
#include "common/database/DatabaseManager.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRelationalDelegate>

RequestsAdminWidget::RequestsAdminWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::RequestsAdminWidget),
model(new QSqlRelationalTableModel(this))
{
    ui->setupUi(this);

    model->setTable("exchange_requests");
    model->setRelation(2, QSqlRelation("currencies", "id", "code"));
    model->setRelation(3, QSqlRelation("currencies", "id", "code"));
    model->setRelation(1, QSqlRelation("users", "id", "username"));
    model->setHeaderData(1, Qt::Horizontal, "User");
    model->setHeaderData(2, Qt::Horizontal, "From");
    model->setHeaderData(3, Qt::Horizontal, "To");
    model->setHeaderData(4, Qt::Horizontal, "Amount");
    model->setHeaderData(5, Qt::Horizontal, "Status");
    model->setHeaderData(8, Qt::Horizontal, "Admin Notes");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->resizeColumnsToContents();

    connect(ui->approveButton, &QPushButton::clicked, this, &RequestsAdminWidget::onApproveClicked);
    connect(ui->rejectButton, &QPushButton::clicked, this, &RequestsAdminWidget::onRejectClicked);
    connect(ui->refreshButton, &QPushButton::clicked, this, &RequestsAdminWidget::updateRequests);
}

RequestsAdminWidget::~RequestsAdminWidget()
{
    delete ui;
}

void RequestsAdminWidget::onApproveClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) return;

    int requestId = model->data(model->index(index.row(), 0)).toInt();
    if (DatabaseManager::instance().updateRequestStatus(requestId, "approved", "Approved by admin")) {
        QMessageBox::information(this, "Success", "Request approved!");
        updateRequests();
    } else {
        QMessageBox::critical(this, "Error", "Failed to approve request");
    }
}

void RequestsAdminWidget::onRejectClicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) return;

    int requestId = model->data(model->index(index.row(), 0)).toInt();
    QString reason = QInputDialog::getText(this, "Rejection Reason", "Enter reason for rejection:");

    if (!reason.isEmpty()) {
        if (DatabaseManager::instance().updateRequestStatus(requestId, "rejected", reason)) {
            QMessageBox::information(this, "Success", "Request rejected!");
            updateRequests();
        } else {
            QMessageBox::critical(this, "Error", "Failed to reject request");
        }
    }
}

void RequestsAdminWidget::updateRequests()
{
    model->select();
    ui->tableView->resizeColumnsToContents();
}
