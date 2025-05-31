#include "ExchangeWidget.h"
#include "ui_ExchangeWidget.h"
#include "../common/database/DatabaseManager.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>

ExchangeWidget::ExchangeWidget(QWidget *parent) :
QWidget(parent),
ui(new Ui::ExchangeWidget),
networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Заполнение списка валют
    auto currencies = DatabaseManager::instance().getAllCurrencies();
    for (const auto &currency : currencies) {
        QString code = currency["code"].toString();
        ui->fromCurrency->addItem(code, currency["id"]);
        ui->toCurrency->addItem(code, currency["id"]);
    }

    connect(ui->convertButton, &QPushButton::clicked, this, &ExchangeWidget::onConvertClicked);
    connect(ui->requestButton, &QPushButton::clicked, this, &ExchangeWidget::onRequestClicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &ExchangeWidget::onApiReply);
}

ExchangeWidget::~ExchangeWidget()
{
    delete ui;
}

void ExchangeWidget::onConvertClicked()
{
    int fromId = ui->fromCurrency->currentData().toInt();
    int toId = ui->toCurrency->currentData().toInt();
    double amount = ui->amount->value();

    if (fromId == toId) {
        QMessageBox::warning(this, "Error", "Cannot convert same currencies");
        return;
    }

    // Запрос к API (пример)
    QString fromCode = ui->fromCurrency->currentText();
    QString url = QString("https://api.exchangerate-api.com/v4/latest/%1").arg(fromCode);
    networkManager->get(QNetworkRequest(QUrl(url)));

    ui->resultLabel->setText("Loading...");
    ui->convertButton->setEnabled(false);
}

void ExchangeWidget::onRequestClicked()
{
    int fromId = ui->fromCurrency->currentData().toInt();
    int toId = ui->toCurrency->currentData().toInt();
    double amount = ui->amount->value();

    // Здесь нужно добавить получение ID текущего пользователя
    int userId = 1; // Заглушка

    int requestId = DatabaseManager::instance().createExchangeRequest(userId, fromId, toId, amount);
    if (requestId > 0) {
        QMessageBox::information(this, "Success", "Exchange request created!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to create request");
    }
}

void ExchangeWidget::onApiReply(QNetworkReply *reply)
{
    ui->convertButton->setEnabled(true);

    if (reply->error() != QNetworkReply::NoError) {
        ui->resultLabel->setText("Network error: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject json = doc.object();
    QString toCode = ui->toCurrency->currentText();

    if (json.contains("rates")) {
        double rate = json["rates"].toObject()[toCode].toDouble();
        double amount = ui->amount->value();
        ui->resultLabel->setText(QString::number(amount * rate, 'f', 2));
        currentRate = rate;
    } else {
        ui->resultLabel->setText("API error");
    }

    reply->deleteLater();
}
