#include "CurrenciesWidget.h"
#include "ui_CurrenciesWidget.h"
#include "../common/database/DatabaseManager.h"
#include <QMessageBox>
#include <QSqlError>

CurrenciesWidget::CurrenciesWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::CurrenciesWidget),
model(new QSqlTableModel(this))
{
    ui->setupUi(this);

    model->setTable("currencies");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    model->setHeaderData(1, Qt::Horizontal, "Code");
    model->setHeaderData(2, Qt::Horizontal, "Name");
    model->setHeaderData(3, Qt::Horizontal, "Rate");

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(0); // ID
    ui->tableView->hideColumn(4); // last_updated

    connect(ui->addButton, &QPushButton::clicked, this, &CurrenciesWidget::onAddCurrency);
    connect(ui->removeButton, &QPushButton::clicked, this, &CurrenciesWidget::onRemoveCurrency);
}

CurrenciesWidget::~CurrenciesWidget()
{
    delete ui;
}

void CurrenciesWidget::onAddCurrency()
{
    int row = model->rowCount();
    model->insertRow(row);
    // Устанавливаем значения по умолчанию для новой валюты
    model->setData(model->index(row, 3), 1.0); // rate
}

void CurrenciesWidget::onRemoveCurrency()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        model->removeRow(index.row());
    }
}

void CurrenciesWidget::updateCurrencies()
{
    model->submitAll();
    model->select();
}
