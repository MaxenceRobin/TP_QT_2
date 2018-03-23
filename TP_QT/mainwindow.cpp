#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dbmanager.h"

#include <QStandardItemModel>
#include <QDebug>

//Regular expressions to control inputs
#define NAME_SEARCH_REG_EXP "[A-ZÀ-ÖØ-Ýa-zà-öø-ÿ]+((-|\\s)[A-ZÀ-ÖØ-Ýa-zà-öø-ÿ]+)*"
#define ID_SEARCH_REG_EXP "[0-9]*"


/**
 * @brief Constructs the main window
 * @param parent The parent QWidget
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), nbrOfDeletedRecords(0)
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
//    clientsProxyModel->setSourceModel(clientsModel);
    ui->clientTableView->setModel(clientsProxyModel);
    refreshClientsView();

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

    QObject::connect(ui->resourcesTreeView, SIGNAL(doubleClicked(QModelIndex)),
                     this, SLOT(showUpdateResource(QModelIndex)));

    QObject::connect(ui->clientTableView, SIGNAL(doubleClicked(QModelIndex)),
                     this, SLOT(showUpdateClient(QModelIndex)));


    ui->deleteResourcePushButton->setEnabled(false);
    ui->deleteClientPushButton->setEnabled(false);

    //Sets the default dates
    on_resetPushButton_clicked();


    refreshResourceView();
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
    AddClientDialog clientDialog(-1, this);

    connect(&clientDialog, SIGNAL(clientAdded()), this, SLOT(updateStatusMessage()));

    if (clientDialog.exec() == QDialog::Accepted)
    {
        //ui->statusBar->showMessage("Vous avez ajouté un client."); Question 7

        refreshClientsView();
    }
    else
    {
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un client.");
    }
}

/**
 * @brief Question 7
 */
void MainWindow::updateStatusMessage()
{
    ui->statusBar->showMessage("Vous avez ajouté un client.");
}


/**
 * @brief Displays the modal dialog window used to add a resource
 */
void MainWindow::showAddResourceDialog()
{
    AddResourceDialog staffDialog(-1, this);
    if (staffDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un personnel.");
        refreshResourceView();
    }
    else
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un personnel.");
}

/**
 * @brief Displays the modal dialog window used to edit a client
 */
void MainWindow::showUpdateClient(QModelIndex index)
{
    const int id = ui->clientTableView->model()->index(index.row(), 0).data().toInt();

    AddClientDialog clientDialog(id, this);

    if (clientDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez édité un client.");
        refreshClientsView();
    }
    else
    {
        ui->statusBar->showMessage("Vous avez annulé l'édition d'un client.");
    }
}

/**
 * @brief Displays the modal dialog window used to edit a resource
 */
void MainWindow::showUpdateResource(QModelIndex index)
{
    // If the index has no parent, it can't be edited
    if (index.parent() == QModelIndex())
    {
        return;
    }

    AddResourceDialog staffDialog(index.data(Qt::UserRole + 1).toInt(), this);

    if (staffDialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez édité un personnel.");
        refreshResourceView();
    }
    else
    {
        ui->statusBar->showMessage("Vous avez annulé l'édition d'un personnel.");
    }
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


/**
 * @brief Refreshes the resources table view
 */
void MainWindow::refreshResourceView()
{
    if (ui->resourcesTreeView->model() != nullptr)
    {
        delete ui->resourcesTreeView->model();
    }

    ui->resourcesTreeView->setModel(DBManager::getNestedResourcesModel());
    ui->resourcesTreeView->expandAll();
}


/**
 * @brief Refreshes the clients table view
 */
void MainWindow::refreshClientsView()
{
    if (clientsModel != nullptr)
        delete clientsModel;
    clientsModel = DBManager::getClientsModel();
    clientsProxyModel->setSourceModel(clientsModel);

    // Question 6;
    ui->clientTableView->sortByColumn(8, Qt::AscendingOrder);
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
    ui->toDateSearchDateEdit->setDate(QDate::currentDate().addMonths(2));

    //Clears the lineEdits
    ui->firstNameSearchLineEdit->clear();
    ui->lastNameSearchLineEdit->clear();
    ui->idSearchLineEdit->clear();
}


/**
 * @brief Handles the resource deletion
 */
void MainWindow::on_deleteResourcePushButton_clicked()
{
    if (ui->resourcesTreeView->selectionModel()->hasSelection())
    {
        QMessageBox::StandardButton confirmDelete;
        confirmDelete = QMessageBox::question(this, "Confirmation suppression",
                "Souhaitez-vous supprimer " + ui->resourcesTreeView->selectionModel()->currentIndex().data().toString() + " ?",
                QMessageBox::Yes|QMessageBox::No);
        if (confirmDelete == QMessageBox::Yes)
        {
            Resource resourceToDelete = DBManager::getResourceById(ui->resourcesTreeView->selectionModel()->currentIndex().data(Qt::UserRole + 1).toInt());
            DBManager::deleteResource(resourceToDelete);
            refreshResourceView();
            ui->statusBar->showMessage("Vous avez supprimé un personnel.");
            //Question 5
            nbrOfDeletedRecords++;
        }
    }
}



/**
 * @brief Enables the resource delete button only when it should be
 * @param index The index of the selection
 */
void MainWindow::on_resourcesTreeView_clicked(const QModelIndex &index)
{
    if (!index.isValid() || index.parent() == QModelIndex())
        ui->deleteResourcePushButton->setEnabled(false);
    else
        ui->deleteResourcePushButton->setEnabled(true);
}


/**
 * @brief Handles the client deletion
 */
void MainWindow::on_deleteClientPushButton_clicked()
{
    if (ui->clientTableView->selectionModel()->hasSelection())
    {
        QMessageBox::StandardButton confirmDelete;

        unsigned int clientId = ui->clientTableView->selectionModel()->selectedRows(DBManager::INDEX_ID_COL_CLIENTS_MODEL).value(0).data().toInt();
        QString clientLName = ui->clientTableView->selectionModel()->selectedRows(DBManager::INDEX_LNAME_COL_CLIENTS_MODEL).value(0).data().toString();
        QString clientFName = ui->clientTableView->selectionModel()->selectedRows(DBManager::INDEX_FNAME_COL_CLIENTS_MODEL).value(0).data().toString();
        confirmDelete = QMessageBox::question(this, "Confirmation suppression",
                "Souhaitez-vous supprimer le client " + clientLName + " " + clientFName + " ?",
                QMessageBox::Yes|QMessageBox::No);
        if (confirmDelete == QMessageBox::Yes)
        {
            DBManager::deleteClient(clientId);
            ui->deleteClientPushButton->setEnabled(false);
            refreshClientsView();
            ui->statusBar->showMessage("Vous avez supprimé un client.");
            //Question 5
            nbrOfDeletedRecords++;
        }
    }
}

/**
 * @brief Enables the client delete button only when it should be
 * @param index The index of the selection
 */
void MainWindow::on_clientTableView_clicked(const QModelIndex &index)
{
    if (index.isValid())
        ui->deleteClientPushButton->setEnabled(true);
    else
        ui->deleteClientPushButton->setEnabled(false);
}

/**
 * @brief Question 3
 */
void MainWindow::showAddLifeInsurerDialog()
{
    AddLifeInsurerDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted)
    {
        ui->statusBar->showMessage("Vous avez ajouté un assureur vie.");
        refreshResourceView();
    }
    else
    {
        ui->statusBar->showMessage("Vous avez annulé l'ajout d'un assureur vie.");
    }
}


/**
 * @brief Question 5
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::information(this, "Nombre d'enregistrements supprimés", QString::number(nbrOfDeletedRecords) + " enregistrement(s) supprimé(s)");
    QMainWindow::closeEvent(event);
}

/**
 * @brief Question 10
 */
void MainWindow::on_exportClientButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter client", QDir::homePath(), "Fichier XML (*.xml)");

    QFile file(filePath);

    if (file.open(QFile::Text | QFile::WriteOnly))
    {
        QString fileContent = "<TClient>\n";

        QList<Client> * clients = DBManager::getClients();

        for (const Client & client : *clients)
        {
            fileContent += QString("<Client id=\"%1\">\n"
                           "\t<Nom>%2</Nom>\n"
                           "\t<Prenom>%3</Prenom>\n"
                           "</Client>\n")
                    .arg(QString::number(client.getId()))
                    .arg(client.getLastName())
                    .arg(client.getFirstName());
        }

        delete clients;

        fileContent += "</TClient>";

        QDataStream writer(&file);

        writer << fileContent;

        file.close();
    }
}
