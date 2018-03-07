#include "addclientwindow.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient()
{
    delete ui;
}
