#include "addresourcestoclientdialog.h"
#include "ui_addresourcestoclientdialog.h"
#include "dbmanager.h"

<<<<<<< HEAD
#include <QDebug>
=======
>>>>>>> origin/master

AddResourcesToClientDialog::AddResourcesToClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddResourcesToClientDialog)
{
    ui->setupUi(this);

<<<<<<< HEAD
    ui->resourcesTableView->setModel(DBManager::getResourcesModel());

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(createResourcesList()));

//    if (ui->resourcesTableView->selectionModel() == NULL)
//        ui->addButton->setEnabled(false);

    //refreshResourcesTableView();
=======
    resourcesModel = DBManager::getResourcesModel();

    resourcesProxyModel = new QSortFilterProxyModel();
    resourcesProxyModel->setSourceModel(resourcesModel);
    //Filters on the resource type column
    resourcesProxyModel->setFilterKeyColumn(DBManager::INDEX_TYPE_COL_RESOURCES_TYPES_MODEL);
    ui->resourcesTableView->setModel(resourcesProxyModel);
    ui->resourcesTableView->setSortingEnabled(true);

    resourcesTypesModel = DBManager::getResourcesTypesModel();
    ui->resourceTypeComboBox->setModel(resourcesTypesModel);

    //The user can't add a resource if none is selected
    if (!ui->resourcesTableView->selectionModel()->hasSelection())
        ui->addButton->setEnabled(false);
>>>>>>> origin/master
}

AddResourcesToClientDialog::~AddResourcesToClientDialog()
{
    if (resourcesTypesModel != nullptr)
        delete resourcesTypesModel;
    if (resourcesModel != nullptr)
        delete resourcesModel;
    if (resourcesProxyModel != nullptr)
        delete resourcesProxyModel;
    delete ui;
}

void AddResourcesToClientDialog::on_resourceTypeComboBox_currentIndexChanged(const QString &resourceType)
{
<<<<<<< HEAD
    if (ui->resourcesTableView->model() != nullptr)
    {
        delete ui->resourcesTableView->model();
    }

    ui->resourcesTableView->setModel(DBManager::getResourcesModel());
=======
    //Filters by
    resourcesProxyModel->setFilterRegExp(resourceType);
    //Resets the selection
    ui->resourcesTableView->selectionModel()->clear();
    ui->addButton->setEnabled(false);
}

void AddResourcesToClientDialog::on_resourcesTableView_clicked(const QModelIndex &index)
{
    //Checks if a resource if selected to allow to click on addButton
    if (ui->resourcesTableView->selectionModel()->hasSelection())
        ui->addButton->setEnabled(true);
    else
        ui->addButton->setEnabled(false);
>>>>>>> origin/master
}

void AddResourcesToClientDialog::createResourcesList()
{
    QList<Resource> resources;

    for (QModelIndex & item : ui->resourcesTableView->selectionModel()->selectedRows())
    {
//        resources << Resource(item.child(0, 0).data(Qt::DisplayRole).toString(),
//                              item.child(0, 1).data(Qt::DisplayRole).toString(),
//                              item.child(0, 2).data(Qt::DisplayRole).toString());

        resources << Resource(ui->resourcesTableView->model()->index(item.row(), 0).data().toString(),
                              ui->resourcesTableView->model()->index(item.row(), 1).data().toString(),
                              ui->resourcesTableView->model()->index(item.row(), 2).data().toString());

        qDebug() << resources.last().getFirstName()
                 << resources.last().getLastName()
                 << resources.last().getStaffType();
    }

    emit newRessources(resources);

    accept();
}
