#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

#include <QStandardItemModel>
#include <QDebug>

//Regular expression to control inputs
#define NAME_SEARCH_REG_EXP "[A-ZÀ-ÖØ-Ýa-zà-öø-ÿ]+((-|\\s)[A-ZÀ-ÖØ-Ýa-zà-öø-ÿ]+)*"
#define ID_SEARCH_REG_EXP "[0-9]*"


/**
 * @brief Constructs the main window
 * @param parent The parent QWidget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("Vous êtes connecté.");


    //Controls the QLineEdit entries
    QRegExp nameSearchRegExp(NAME_SEARCH_REG_EXP);
    QValidator * nameSearchValidator = new QRegExpValidator(nameSearchRegExp, this);
    ui->lastNameSearchLineEdit->setValidator(nameSearchValidator);
    ui->firstNameSearchLineEdit->setValidator(nameSearchValidator);

    QRegExp idSearchRegExp(ID_SEARCH_REG_EXP);
    QValidator * idSearchValidator = new QRegExpValidator(idSearchRegExp, this);
    ui->idSearchLineEdit->setValidator(idSearchValidator);


    //Sets the clientTableView model and filter
    clientsModel = DBManager::getClientsModel();
    clientsProxyModel = new ClientsSortFilterProxyModel(this);
    clientsProxyModel->setSourceModel(clientsModel);
    ui->clientTableView->setModel(clientsProxyModel);

    //Connects the text/dateChanged signals to the proxy model
    QObject::connect(ui->idSearchLineEdit, &QLineEdit::textChanged,
                     clientsProxyModel, &ClientsSortFilterProxyModel::setIdFilter);
    QObject::connect(ui->lastNameSearchLineEdit, &QLineEdit::textChanged,
                     clientsProxyModel, &ClientsSortFilterProxyModel::setLastNameFilter);
    QObject::connect(ui->firstNameSearchLineEdit, &QLineEdit::textChanged,
                     clientsProxyModel, &ClientsSortFilterProxyModel::setFirstNameFilter);
    QObject::connect(ui->fromDateSearchDateEdit, &QDateEdit::dateChanged,
                     clientsProxyModel, &ClientsSortFilterProxyModel::setMinDate);
    QObject::connect(ui->toDateSearchDateEdit, &QDateEdit::dateChanged,
                     clientsProxyModel, &ClientsSortFilterProxyModel::setMaxDate);

    //Sets the default dates
    on_resetPushButton_clicked();


    refreshStaffView();
}


/**
 * @brief Destructs the main window and it's components and models
 */
MainWindow::~MainWindow()
{
    if (clientsModel != nullptr)
        delete clientsModel;
    delete ui;
}


/**
 * @brief Displays the modal dialog window used to add a client
 */
void MainWindow::showAddClientDialog()
{
    AddClientDialog clientDialog(this);

    if (clientDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un client.");

        if (clientsModel != nullptr)
            delete clientsModel;
        clientsModel = DBManager::getClientsModel();
    }
    else
    {
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un client.");
    }
}


/**
 * @brief Displays the modal dialog window used to add a resource
 */
void MainWindow::showAddResourceDialog()
{
    AddResourceDialog staffDialog(UtilisationType::Create, this);
    if (staffDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un personnel.");
        refreshStaffView();
    }
    else
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un personnel.");
}


/**
 * @brief Displays the modal about dialog window
 */
void MainWindow::showAboutDialog()
{
    AboutDialog aboutDialog;
    aboutDialog.exec();
}


/**
 * @brief Avoids the max date search to be smaller than the min date
 * @param date The new min date
 */
void MainWindow::on_fromDateSearchDateEdit_userDateChanged(const QDate &date)
{
    if (ui->toDateSearchDateEdit->date() < date)
    {
        ui->toDateSearchDateEdit->setDate(date);
    }

    ui->toDateSearchDateEdit->setMinimumDate(date);
}

void MainWindow::refreshStaffView()
{
    if (ui->resourcesTreeView->model() != nullptr)
    {
        delete ui->resourcesTreeView->model();
    }

    ui->resourcesTreeView->setModel(DBManager::getNestedResourcesModel());
    ui->resourcesTreeView->expandAll();
}


/**
 * @brief Resets the search filters to their default values
 * The min search date is set to the current date -2 month
 * The max search date is set to the current date +2 month
 * The lineEdits are cleared
 */
void MainWindow::on_resetPushButton_clicked()
{
    //Sets the min date to current date -2 months, max date to current date +2 months
    ui->fromDateSearchDateEdit->setDate(QDate::currentDate().addMonths(-2));
    ui->toDateSearchDateEdit->setMinimumDate(ui->fromDateSearchDateEdit->date());
    ui->toDateSearchDateEdit->setDate(QDate::currentDate().addMonths(4));

    //Clears the lineEdits
    ui->firstNameSearchLineEdit->clear();
    ui->lastNameSearchLineEdit->clear();
    ui->idSearchLineEdit->clear();
    ui->resourcesTreeView->expandAll();
}
