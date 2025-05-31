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
