/********************************************************************************
** Form generated from reading UI file 'ExchangeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCHANGEWIDGET_H
#define UI_EXCHANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExchangeWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *amount;
    QLabel *label_2;
    QComboBox *fromCurrency;
    QLabel *label_3;
    QComboBox *toCurrency;
    QPushButton *convertButton;
    QLabel *resultLabel;
    QPushButton *requestButton;

    void setupUi(QWidget *ExchangeWidget)
    {
        if (ExchangeWidget->objectName().isEmpty())
            ExchangeWidget->setObjectName("ExchangeWidget");
        gridLayout = new QGridLayout(ExchangeWidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ExchangeWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        amount = new QDoubleSpinBox(ExchangeWidget);
        amount->setObjectName("amount");
        amount->setMinimum(0.010000000000000);
        amount->setMaximum(1000000.000000000000000);
        amount->setValue(100.000000000000000);

        gridLayout->addWidget(amount, 0, 1, 1, 1);

        label_2 = new QLabel(ExchangeWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        fromCurrency = new QComboBox(ExchangeWidget);
        fromCurrency->setObjectName("fromCurrency");

        gridLayout->addWidget(fromCurrency, 1, 1, 1, 1);

        label_3 = new QLabel(ExchangeWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        toCurrency = new QComboBox(ExchangeWidget);
        toCurrency->setObjectName("toCurrency");

        gridLayout->addWidget(toCurrency, 2, 1, 1, 1);

        convertButton = new QPushButton(ExchangeWidget);
        convertButton->setObjectName("convertButton");

        gridLayout->addWidget(convertButton, 3, 0, 1, 2);

        resultLabel = new QLabel(ExchangeWidget);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignCenter);
        resultLabel->setStyleSheet(QString::fromUtf8("font-size: 16pt; font-weight: bold;"));

        gridLayout->addWidget(resultLabel, 4, 0, 1, 2);

        requestButton = new QPushButton(ExchangeWidget);
        requestButton->setObjectName("requestButton");

        gridLayout->addWidget(requestButton, 5, 0, 1, 2);


        retranslateUi(ExchangeWidget);

        QMetaObject::connectSlotsByName(ExchangeWidget);
    } // setupUi

    void retranslateUi(QWidget *ExchangeWidget)
    {
        label->setText(QCoreApplication::translate("ExchangeWidget", "Amount:", nullptr));
        label_2->setText(QCoreApplication::translate("ExchangeWidget", "From:", nullptr));
        label_3->setText(QCoreApplication::translate("ExchangeWidget", "To:", nullptr));
        convertButton->setText(QCoreApplication::translate("ExchangeWidget", "Convert", nullptr));
        resultLabel->setText(QCoreApplication::translate("ExchangeWidget", "Result will be shown here", nullptr));
        requestButton->setText(QCoreApplication::translate("ExchangeWidget", "Create Exchange Request", nullptr));
        (void)ExchangeWidget;
    } // retranslateUi

};

namespace Ui {
    class ExchangeWidget: public Ui_ExchangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCHANGEWIDGET_H
