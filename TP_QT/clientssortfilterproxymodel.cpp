#include "clientssortfilterproxymodel.h"

/**
 * @brief Constructs the SortFilterProxyModel
 * @param parent
 */
ClientsSortFilterProxyModel::ClientsSortFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    //case insensitive search
    mLastNameRegExp.setCaseSensitivity(Qt::CaseInsensitive);
    mFirstNameRegExp.setCaseSensitivity(Qt::CaseInsensitive);

    //how are the regular expression transmitted
    mLastNameRegExp.setPatternSyntax(QRegExp::FixedString);
    mFirstNameRegExp.setPatternSyntax(QRegExp::FixedString);
}


/**
 * @brief Filters the source model
 * @param source_row The source row
 * @param source_parent The source parent
 * @return True if the row respects the filter, False esle
 */
bool ClientsSortFilterProxyModel::filterAcceptsRow(int source_row,
                const QModelIndex &source_parent) const
{
    QModelIndex idIndex = sourceModel()->index(source_row, DBManager::INDEX_ID_COL_CLIENTS_MODEL, source_parent);
    QModelIndex lNameIndex = sourceModel()->index(source_row, DBManager::INDEX_LNAME_COL_CLIENTS_MODEL, source_parent);
    QModelIndex fNameIndex = sourceModel()->index(source_row, DBManager::INDEX_FNAME_COL_CLIENTS_MODEL, source_parent);
    QModelIndex dateIndex = sourceModel()->index(source_row, DBManager::INDEX_DATE_COL_CLIENTS_MODEL, source_parent);

    return ((sourceModel()->data(idIndex).toString().contains(mIdRegExp)
            && sourceModel()->data(lNameIndex).toString().contains(mLastNameRegExp)
            && sourceModel()->data(fNameIndex).toString().contains(mFirstNameRegExp))
            && dateIsInRange(sourceModel()->data(dateIndex).toDate()));
}


/**
 * @brief Determines if the date is between the two filter dates
 * @param date The date to test
 * @return True if the date is between the two filter dates
 */
bool ClientsSortFilterProxyModel::dateIsInRange(const QDate &date) const
{
    return (date >= mMinDate && date <= mMaxDate);
}
