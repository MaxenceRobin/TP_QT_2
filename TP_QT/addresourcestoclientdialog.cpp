#include "addresourcestoclientdialog.h"
#include "ui_addresourcestoclientdialog.h"
#include "dbmanager.h"

AddResourcesToClientDialog::AddResourcesToClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddResourcesToClientDialog)
{
    ui->setupUi(this);
    if (ui->resourcesTableView->selectionModel() == NULL)
        ui->addButton->setEnabled(false);
    ui->resourcesTableView->setModel(DBManager::getResourcesModel());
}

AddResourcesToClientDialog::~AddResourcesToClientDialog()
{
    delete ui;
}
