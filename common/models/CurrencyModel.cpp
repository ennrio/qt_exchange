#include "CurrencyModel.h"
#include "../common/database/DatabaseManager.h"

CurrencyModel::CurrencyModel(QObject *parent) : QAbstractTableModel(parent)
{
    updateData();
}

int CurrencyModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : currencies.size();
}

int CurrencyModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 4; // id, code, name, rate
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    if (index.row() >= currencies.size() || index.row() < 0)
        return QVariant();

    const QVariantMap &currency = currencies.at(index.row());

    switch (index.column()) {
        case 0: return currency["id"];
        case 1: return currency["code"];
        case 2: return currency["name"];
        case 3: return currency["rate"];
        default: return QVariant();
    }
}

QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
        case 0: return "ID";
        case 1: return "Code";
        case 2: return "Name";
        case 3: return "Rate";
        default: return QVariant();
    }
}

void CurrencyModel::updateData()
{
    beginResetModel();
    currencies = DatabaseManager::instance().getAllCurrencies();
    endResetModel();
}

Qt::ItemFlags CurrencyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    // Разрешаем редактирование только для колонки с курсом (rate)
    if (index.column() == 3) {
        return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    }

    return QAbstractTableModel::flags(index);
}

bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole || index.column() != 3) // Только курс можно редактировать
        return false;

    if (index.row() >= currencies.size() || index.row() < 0)
        return false;

    QVariantMap &currency = currencies[index.row()];
    double newRate = value.toDouble();

    // Обновляем в базе данных
    int currencyId = currency["id"].toInt();
    if (DatabaseManager::instance().updateCurrencyRate(currencyId, newRate)) {
        currency["rate"] = newRate;
        emit dataChanged(index, index, {role});
        return true;
    }

    return false;
}

bool DatabaseManager::updateCurrencyRate(int currencyId, double rate)
{
    QSqlQuery query;
    query.prepare("UPDATE currencies SET rate = ? WHERE id = ?");
    query.addBindValue(rate);
    query.addBindValue(currencyId);
    return query.exec();
}
