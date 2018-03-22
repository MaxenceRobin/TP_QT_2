#ifndef CLIENTSSORTFILTERPROXYMODEL_H
#define CLIENTSSORTFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>
#include <QDate>

class ClientsSortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

private:
    QDate mMinDate;
    QDate mMaxDate;
    QString mLastName;
    QString mFirstName;
    long unsigned int mId;

public:
    ClientsSortFilterProxyModel(QObject *parent = 0);

    //Accessors
    QDate getMinDate() const { return mMinDate; }
    void setMinDate(const QDate &minDate) { mMinDate = minDate; }

    QDate getMaxDate() const { return mMaxDate; }
    void setMaxDate(const QDate &maxDate) { mMaxDate = maxDate; }

    QString getLastName() const { return mLastName; }
    void setLastName(const QString &lastName) { mLastName = lastName; }

    QString getLastName() const { return mLastName; }
    void setLastName(const QString &lastName) { mLastName = lastName; }

    long unsigned int getId() const { return mId; }
    void setId(const long unsigned int id) { mId = id; }

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

#endif // CLIENTSSORTFILTERPROXYMODEL_H
