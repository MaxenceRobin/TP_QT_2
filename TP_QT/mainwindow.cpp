#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous êtes connecté.");

    ui->fromDateSearchDateEdit->setDate(QDate::currentDate());
    ui->toDateSearchDateEdit->setMinimumDate(ui->fromDateSearchDateEdit->date());
    ui->toDateSearchDateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddClientDialog()
{
    AddClientDialog clientDialog(this);
    if (clientDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un client.");
    }
    else
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un client.");
}


void MainWindow::showAddStaffDialog()
{
    AddStaffDialog staffDialog(this);
    if (staffDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un personnel.");
    }
    else
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un personnel.");
}


void MainWindow::showAboutDialog()
{
    AboutDialog aboutDialog;
    aboutDialog.exec();
}

void MainWindow::on_fromDateSearchDateEdit_userDateChanged(const QDate &date)
{
    ui->toDateSearchDateEdit->setMinimumDate(ui->fromDateSearchDateEdit->date());
    ui->toDateSearchDateEdit->setDate(QDate::currentDate());
}
