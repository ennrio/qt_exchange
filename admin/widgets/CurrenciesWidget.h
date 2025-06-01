#ifndef CURRENCIESWIDGET_H
#define CURRENCIESWIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
    class CurrenciesWidget;
}

class CurrenciesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CurrenciesWidget(QWidget *parent = nullptr);
    ~CurrenciesWidget();

public slots:
    void updateCurrencies();

private slots:
    void onAddCurrency();
    void onRemoveCurrency();

private:
    Ui::CurrenciesWidget *ui;
    QSqlTableModel *model;
};

#endif // CURRENCIESWIDGET_H
