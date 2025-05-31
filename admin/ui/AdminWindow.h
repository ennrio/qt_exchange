#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "../widgets/UsersWidget.h"
#include "../widgets/CurrenciesWidget.h"
#include "../widgets/RequestsAdminWidget.h"

namespace Ui {
    class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private:
    Ui::AdminWindow *ui;
    QTabWidget *tabWidget;
    UsersWidget *usersWidget;
    CurrenciesWidget *currenciesWidget;
    RequestsAdminWidget *requestsWidget;
};

#endif // ADMINWINDOW_H
