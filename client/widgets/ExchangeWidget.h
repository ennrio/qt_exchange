#ifndef EXCHANGEWIDGET_H
#define EXCHANGEWIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
    class ExchangeWidget;
}

class ExchangeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExchangeWidget(QWidget *parent = nullptr);
    ~ExchangeWidget();

private slots:
    void onConvertClicked();
    void onRequestClicked();
    void onApiReply(QNetworkReply *reply);

private:
    Ui::ExchangeWidget *ui;
    QNetworkAccessManager *networkManager;
    double currentRate = 0.0;
};

#endif // EXCHANGEWIDGET_H
