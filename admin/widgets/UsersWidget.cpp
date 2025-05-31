#include "UsersWidget.h"
#include "ui_UsersWidget.h"
#include "common/database/DatabaseManager.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlTableModel>

UsersWidget::UsersWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::UsersWidget),
model(new QSqlTableModel(this))
{
    ui->setupUi(this);

    model->setTable("users");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Username");
    model->setHeaderData(3, Qt::Horizontal, "Full Name");
    model->setHeaderData(4, Qt::Horizontal, "Role");

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0); // ID
    ui->tableView->hideColumn(2); // Password hash
    ui->tableView->hideColumn(5); // Created at

    connect(ui->addButton, &QPushButton::clicked, this, &UsersWidget::onAddUser);
    connect(ui->deleteButton, &QPushButton::clicked, this, &UsersWidget::onDeleteUser);
}

UsersWidget::~UsersWidget()
{
    delete ui;
}

void UsersWidget::onAddUser()
{
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row, 4), "user"); // Default role
}

void UsersWidget::onDeleteUser()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        model->removeRow(index.row());
    }
}
