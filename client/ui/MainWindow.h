#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "../widgets/ExchangeWidget.h"
#include "../widgets/RequestsWidget.h"
#include "../widgets/ProfileWidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    ExchangeWidget *exchangeWidget;
    RequestsWidget *requestsWidget;
    ProfileWidget *profileWidget;
};

#endif // MAINWINDOW_H
