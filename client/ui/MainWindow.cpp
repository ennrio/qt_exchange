#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    exchangeWidget = new ExchangeWidget(this);
    requestsWidget = new RequestsWidget(this);
    profileWidget = new ProfileWidget(this);

    stackedWidget->addWidget(exchangeWidget);
    stackedWidget->addWidget(requestsWidget);
    stackedWidget->addWidget(profileWidget);

    // Навигация
    connect(ui->actionExchange, &QAction::triggered, [=](){
        stackedWidget->setCurrentWidget(exchangeWidget);
    });
    connect(ui->actionRequests, &QAction::triggered, [=](){
        stackedWidget->setCurrentWidget(requestsWidget);
    });
    connect(ui->actionProfile, &QAction::triggered, [=](){
        stackedWidget->setCurrentWidget(profileWidget);
    });
    connect(ui->actionExit, &QAction::triggered, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
