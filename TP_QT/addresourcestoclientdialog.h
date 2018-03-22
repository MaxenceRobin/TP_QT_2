#ifndef ADDRESOURCESTOCLIENTDIALOG_H
#define ADDRESOURCESTOCLIENTDIALOG_H

#include <QDialog>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>

#include "resource.h"

namespace Ui {
class AddResourcesToClientDialog;
}

class AddResourcesToClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddResourcesToClientDialog(QWidget *parent = 0);
    ~AddResourcesToClientDialog();

private slots:
    void on_resourceTypeComboBox_currentIndexChanged(const QString &resourceType);
    //void createResourcesList();
    void on_resourcesTableView_clicked(const QModelIndex &index);

private:
    Ui::AddResourcesToClientDialog *ui;
    QSqlQueryModel *resourcesTypesModel;
    QSqlQueryModel *resourcesModel;
    QSortFilterProxyModel *resourcesProxyModel;

signals:
    void newResources(QList<Resource> * resources);
    //void newResourcesTest(QModelIndexList model);
};

#endif // ADDRESOURCESTOCLIENTDIALOG_H
