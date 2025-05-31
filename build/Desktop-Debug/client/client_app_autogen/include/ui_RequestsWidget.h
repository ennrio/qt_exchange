/********************************************************************************
** Form generated from reading UI file 'RequestsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTSWIDGET_H
#define UI_REQUESTSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QPushButton *refreshButton;

    void setupUi(QWidget *RequestsWidget)
    {
        if (RequestsWidget->objectName().isEmpty())
            RequestsWidget->setObjectName("RequestsWidget");
        verticalLayout = new QVBoxLayout(RequestsWidget);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(RequestsWidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        refreshButton = new QPushButton(RequestsWidget);
        refreshButton->setObjectName("refreshButton");

        verticalLayout->addWidget(refreshButton);


        retranslateUi(RequestsWidget);

        QMetaObject::connectSlotsByName(RequestsWidget);
    } // setupUi

    void retranslateUi(QWidget *RequestsWidget)
    {
        refreshButton->setText(QCoreApplication::translate("RequestsWidget", "Refresh", nullptr));
        (void)RequestsWidget;
    } // retranslateUi

};

namespace Ui {
    class RequestsWidget: public Ui_RequestsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTSWIDGET_H
