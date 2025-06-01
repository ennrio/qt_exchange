#include "AdminWindow.h"
#include "ui_AdminWindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    // Создаем виджеты
    usersWidget = new UsersWidget(this);
    currenciesWidget = new CurrenciesWidget(this);
    requestsWidget = new RequestsAdminWidget(this);

    // Добавляем виджеты в табы
    ui->tabWidget->widget(0)->layout()->addWidget(usersWidget);
    ui->tabWidget->widget(1)->layout()->addWidget(currenciesWidget);
    ui->tabWidget->widget(2)->layout()->addWidget(requestsWidget);

    // Настройка соединений
    connect(ui->actionRefresh, &QAction::triggered, [this](){
        switch(ui->tabWidget->currentIndex()) {
            case 0:
                usersWidget->updateUsersTable(); // ИСПРАВЛЕНИЕ: новое имя
                break;
            case 1:
                currenciesWidget->updateCurrencies();
                break;
            case 2:
                requestsWidget->updateRequests();
                break;
        }
    });
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
