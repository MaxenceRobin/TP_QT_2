#include "addresourcestoclientdialog.h"
#include "ui_addresourcestoclientdialog.h"
#include "dbmanager.h"

#include <QDebug>

AddResourcesToClientDialog::AddResourcesToClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddResourcesToClientDialog)
{
    ui->setupUi(this);

    ui->resourcesTableView->setModel(DBManager::getResourcesModel());

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(createResourcesList()));

//    if (ui->resourcesTableView->selectionModel() == NULL)
//        ui->addButton->setEnabled(false);

    //refreshResourcesTableView();
}

AddResourcesToClientDialog::~AddResourcesToClientDialog()
{
    delete ui;
}

void AddResourcesToClientDialog::refreshResourcesTableView()
{
    if (ui->resourcesTableView->model() != nullptr)
    {
        delete ui->resourcesTableView->model();
    }

    ui->resourcesTableView->setModel(DBManager::getResourcesModel());
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
