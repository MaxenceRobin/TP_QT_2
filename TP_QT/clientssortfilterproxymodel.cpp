#include "clientssortfilterproxymodel.h"

ClientsSortFilterProxyModel::ClientsSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}


bool ClientsSortFilterProxyModel::filterAcceptsRow(int source_row,
                const QModelIndex &source_parent) const
{
    return true;
}
