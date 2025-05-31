#ifndef USERSWIDGET_H
#define USERSWIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
    class UsersWidget;
}

class UsersWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UsersWidget(QWidget *parent = nullptr);
    ~UsersWidget();

private slots:
    void onAddUser();
    void onDeleteUser();

private:
    Ui::UsersWidget *ui;
    QSqlTableModel *model;
};

#endif // USERSWIDGET_H
