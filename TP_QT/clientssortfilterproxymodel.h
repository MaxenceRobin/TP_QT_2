#ifndef CLIENTSSORTFILTERPROXYMODEL_H
#define CLIENTSSORTFILTERPROXYMODEL_H

#include <QObject>
#include <QApplication>
#include <QtWidgets>
#include <QSortFilterProxyModel>
#include <QDate>
#include <dbmanager.h>


/**
 * @brief Class inherited from QSortFilterProxyModel used to filter the main window client model
 * @see QSortFilterProxyModel
 */
class ClientsSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

private:
    QDate mMinDate;
    QDate mMaxDate;
    QRegExp mLastNameRegExp;
    QRegExp mFirstNameRegExp;
    QRegExp mIdRegExp;

    bool dateIsInRange (const QDate &date) const;

public:
    explicit ClientsSortFilterProxyModel(QObject *parent = 0);

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

public slots:
    //Slots to update the filters
    void setMinDate(const QDate &minDate) { mMinDate = minDate; invalidateFilter(); }

    void setMaxDate(const QDate &maxDate) { mMaxDate = maxDate; invalidateFilter(); }

    void setLastNameFilter(const QString &lastNameRegExp)
        { mLastNameRegExp.setPattern(lastNameRegExp); invalidateFilter() ; }

    void setFirstNameFilter(const QString &firstNameRegExp)
        { mFirstNameRegExp.setPattern(firstNameRegExp); invalidateFilter() ; }

    void setIdFilter(const QString &idRegExp)
        { mIdRegExp.setPattern(idRegExp); invalidateFilter() ; }

};

#endif // CLIENTSSORTFILTERPROXYMODEL_H
