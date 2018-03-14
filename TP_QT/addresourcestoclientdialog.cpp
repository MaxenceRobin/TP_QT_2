#include "addresourcestoclientdialog.h"
#include "ui_addresourcestoclientdialog.h"

AddResourcesToClientDialog::AddResourcesToClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddResourcesToClientDialog)
{
    ui->setupUi(this);

    if (ui->resourcesListView->selectionModel() == NULL)
        ui->addButton->setEnabled(false);
}

AddResourcesToClientDialog::~AddResourcesToClientDialog()
{
    delete ui;
}
