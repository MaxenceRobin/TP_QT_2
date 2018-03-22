#include "addresourcestoclientdialog.h"
#include "ui_addresourcestoclientdialog.h"
#include "dbmanager.h"

#include <QDebug>

AddResourcesToClientDialog::AddResourcesToClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddResourcesToClientDialog)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(createResourcesList()));

    resourcesModel = DBManager::getResourcesModel();

    resourcesProxyModel = new QSortFilterProxyModel(this);
    resourcesProxyModel->setSourceModel(resourcesModel);
    //Filters on the resource type column
    resourcesProxyModel->setFilterKeyColumn(DBManager::INDEX_TYPE_COL_RESOURCES_TYPES_MODEL);
    ui->resourcesTableView->setModel(resourcesProxyModel);
    ui->resourcesTableView->setSortingEnabled(true);
    ui->resourcesTableView->horizontalHeader()->hideSection(0);

    resourcesTypesModel = DBManager::getResourcesTypesModel();
    ui->resourceTypeComboBox->setModel(resourcesTypesModel);

    //The user can't add a resource if none is selected
    if (!ui->resourcesTableView->selectionModel()->hasSelection())
        ui->addButton->setEnabled(false);
}

AddResourcesToClientDialog::~AddResourcesToClientDialog()
{
    if (resourcesTypesModel != nullptr)
        delete resourcesTypesModel;
    if (resourcesModel != nullptr)
        delete resourcesModel;
    delete ui;
}

void AddResourcesToClientDialog::on_resourceTypeComboBox_currentIndexChanged(const QString &resourceType)
{
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
}

void AddResourcesToClientDialog::createResourcesList()
{
    QList<Resource> resources;

    emit newResourcesTest(ui->resourcesTableView->selectionModel()->selectedRows());

//    for (QModelIndex & item : ui->resourcesTableView->selectionModel()->selectedRows())
//    {
////        resources << Resource(item.child(0, 0).data(Qt::DisplayRole).toString(),
////                              item.child(0, 1).data(Qt::DisplayRole).toString(),
////                              item.child(0, 2).data(Qt::DisplayRole).toString());

//        resources << Resource(ui->resourcesTableView->model()->index(item.row(), 1).data().toString(),
//                              ui->resourcesTableView->model()->index(item.row(), 2).data().toString(),
//                              ui->resourcesTableView->model()->index(item.row(), 3).data().toString(),
//                              ui->resourcesTableView->model()->index(item.row(), 0).data().toInt());

//        qDebug() << resources.last().getId()
//                 << resources.last().getFirstName()
//                 << resources.last().getLastName()
//                 << resources.last().getStaffType();
//    }

//    emit newResources(resources);
}
