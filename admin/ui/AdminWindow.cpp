#include "AdminWindow.h"
#include "ui_AdminWindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    tabWidget = new QTabWidget(this);
    setCentralWidget(tabWidget);

    usersWidget = new UsersWidget(this);
    currenciesWidget = new CurrenciesWidget(this);
    requestsWidget = new RequestsAdminWidget(this);

    tabWidget->addTab(usersWidget, "Users");
    tabWidget->addTab(currenciesWidget, "Currencies");
    tabWidget->addTab(requestsWidget, "Exchange Requests");
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
