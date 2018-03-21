#ifndef ADDRESOURCESTOCLIENTDIALOG_H
#define ADDRESOURCESTOCLIENTDIALOG_H

#include <QDialog>
<<<<<<< HEAD
#include "resource.h"
=======
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>
>>>>>>> origin/master

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

    void on_resourcesTableView_clicked(const QModelIndex &index);

private:
    Ui::AddResourcesToClientDialog *ui;
<<<<<<< HEAD

private slots:
    void refreshResourcesTableView();
    void createResourcesList();

signals:

    void newRessources(QList<Resource> resources);
=======
    QSqlQueryModel *resourcesTypesModel;
    QSqlQueryModel *resourcesModel;
    QSortFilterProxyModel *resourcesProxyModel;
>>>>>>> origin/master
};

#endif // ADDRESOURCESTOCLIENTDIALOG_H
