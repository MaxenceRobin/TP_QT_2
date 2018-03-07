#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous êtes connecté.");
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
