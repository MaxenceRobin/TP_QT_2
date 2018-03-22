#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

//Regular expression to control inputs
#define NAME_SEARCH_REG_EXP "[A-Za-z]+((-|\\s)[A-Za-z]+)*"
#define ID_SEARCH_REG_EXP "[0-9]*"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous êtes connecté.");

    ui->fromDateSearchDateEdit->setDate(QDate::currentDate());
    ui->toDateSearchDateEdit->setMinimumDate(ui->fromDateSearchDateEdit->date());
    ui->toDateSearchDateEdit->setDate(QDate::currentDate());

    QRegExp nameSearchRegExp(NAME_SEARCH_REG_EXP);
    QValidator * nameSearchValidator = new QRegExpValidator(nameSearchRegExp, this);
    ui->lastNameSearchLineEdit->setValidator(nameSearchValidator);
    ui->firstNameSearchLineEdit->setValidator(nameSearchValidator);

    QRegExp idSearchRegExp(ID_SEARCH_REG_EXP);
    QValidator * idSearchValidator = new QRegExpValidator(idSearchRegExp, this);
    ui->idSearchLineEdit->setValidator(idSearchValidator);

    ui->clientTableView->setModel(DBManager::getClientsModel());
}

MainWindow::~MainWindow()
{
    if (ui->clientTableView->model() != nullptr)
        delete ui->clientTableView->model();
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
    {
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un client.");
    }
}


void MainWindow::showAddResourceDialog()
{
    AddResourceDialog staffDialog(this);
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
    if (ui->toDateSearchDateEdit->date() < date)
    {
        ui->toDateSearchDateEdit->setDate(date);
    }

    ui->toDateSearchDateEdit->setMinimumDate(date);
}
