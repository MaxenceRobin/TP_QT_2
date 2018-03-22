#include "clientssortfilterproxymodel.h"

ClientsSortFilterProxyModel::ClientsSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    mLastNameRegExp.setCaseSensitivity(Qt::CaseInsensitive);
    mFirstNameRegExp.setCaseSensitivity(Qt::CaseInsensitive);

    mLastNameRegExp.setPatternSyntax(QRegExp::FixedString);
    mFirstNameRegExp.setPatternSyntax(QRegExp::FixedString);
}


bool ClientsSortFilterProxyModel::filterAcceptsRow(int source_row,
                const QModelIndex &source_parent) const
{
    QModelIndex idIndex = sourceModel()->index(source_row, DBManager::INDEX_ID_COL_CLIENTS_MODEL, source_parent);
    QModelIndex lNameIndex = sourceModel()->index(source_row, DBManager::INDEX_LNAME_COL_CLIENTS_MODEL, source_parent);
    QModelIndex fNameIndex = sourceModel()->index(source_row, DBManager::INDEX_FNAME_COL_CLIENTS_MODEL, source_parent);
    QModelIndex dateIndex = sourceModel()->index(source_row, DBManager::INDEX_DATE_COL_CLIENTS_MODEL, source_parent);

    return ((sourceModel()->data(idIndex).toString().contains(mIdRegExp)
            || sourceModel()->data(lNameIndex).toString().contains(mLastNameRegExp)
            || sourceModel()->data(fNameIndex).toString().contains(mFirstNameRegExp))
            && dateIsInRange(sourceModel()->data(dateIndex).toDate()));
}


bool ClientsSortFilterProxyModel::dateIsInRange(const QDate &date) const
{
    return (date >= mMinDate && date <= mMaxDate);
}
