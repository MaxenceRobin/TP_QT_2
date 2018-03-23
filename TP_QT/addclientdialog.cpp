#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "qmessagebox.h"
#include "resource.h"
#include "dbmanager.h"

#include <QDebug>

//Regular expression to control inputs
#define NAME_REG_EXP "[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*((-|\\s)[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*)*"
#define FR_POSTAL_CODE_REG_EXP "[0-9]{5}"
#define FR_PHONE_NUMBER_REG_EXP "0[0-9]{9}"

//Input error messages
#define ERROR_MSG_CODE_POSTAL_INPUT "Code postal incorrect - Doit être composé de 5 chiffres"
#define ERROR_MSG_PHONE_NUMBER_INPUT "Numéro de téléphone incorrect - Doit être composé de 10 chiffres"
#define ERROR_MSG_COMPULSORY_INPUT "Tous les champs obligatoires (*) doivent être complétés"


AddClientDialog::AddClientDialog(int idClient, QWidget *parent) :
    mIdClient(idClient), QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    ui->appointmentDayCalendar->setSelectedDate(QDate::currentDate());
    ui->appointmentDayCalendar->setMinimumDate(QDate::currentDate());

    //Checks the input of a correct name
    QRegExp nameRegExp(NAME_REG_EXP);
    QValidator * nameValidator = new QRegExpValidator(nameRegExp, this);
    ui->nameLineEdit->setValidator(nameValidator);
    ui->firstNameLineEdit->setValidator(nameValidator);
    ui->cityLineEdit->setValidator(nameValidator);

    //Checks the input of a correct French postal code
    QRegExp postalCodeRegExp(FR_POSTAL_CODE_REG_EXP);
    QValidator * postalCodeValidator = new QRegExpValidator(postalCodeRegExp, this);
    ui->postalCodeLineEdit->setValidator(postalCodeValidator);

    //Checks the input of a correct French phone number
    QRegExp phoneNumRegExp(FR_PHONE_NUMBER_REG_EXP);
    QValidator * phoneNumValidator = new QRegExpValidator(phoneNumRegExp, this);
    ui->phoneNumLineEdit->setValidator(phoneNumValidator);

    ui->resourcesTableView->horizontalHeader()->hideSection(0);


    resourceDialog = new AddResourcesToClientDialog(this);

    QObject::connect(resourceDialog, SIGNAL(newResources(QList<Resource>)), this, SLOT(getNewResources(QList<Resource>)));

    if (mIdClient != -1)
    {
        //setWindowTitle("Editer un client");

        Client client = DBManager::getClientById(mIdClient);

        ui->nameLineEdit->setText(client.getLastName());
        ui->firstNameLineEdit->setText(client.getFirstName());
        ui->addressLineEdit->setText(client.getAddress());
        ui->cityLineEdit->setText(client.getCity());
        ui->postalCodeLineEdit->setText(QString::number(client.getPostalCode()));
        ui->appointmentDayCalendar->setSelectedDate(client.getAppointmentDay());
        ui->rdvDurationSpinBox->setValue(client.getAppointmentDuration());
        ui->phoneNumLineEdit->setText(QString::number(client.getPhoneNumber()));
        ui->prioritySpinBox->setValue(client.getPriority());
        ui->commentTextEdit->setPlainText(client.getComment());

        QStandardItemModel * model = new QStandardItemModel(this);

        QStandardItem * root = model->invisibleRootItem();

        unsigned int row = root->rowCount();

        for (const Resource & resource : client.getResources())
        {
            QStandardItem * idItem =
                    new QStandardItem((QString::number(resource.getId())));

            QStandardItem * lastNameItem =
                    new QStandardItem(resource.getLastName());

            QStandardItem * firstNameItem =
                    new QStandardItem(resource.getFirstName());

            QStandardItem * typeItem =
                    new QStandardItem(resource.getResourceType());

            model->setItem(row, 0, idItem);
            model->setItem(row, 1, lastNameItem);
            model->setItem(row, 2, firstNameItem);
            model->setItem(row, 3, typeItem);

            row++;
        }

        ui->resourcesTableView->setModel(model);
    }
}

AddClientDialog::~AddClientDialog()
{
    if (resourceDialog != NULL)
        delete resourceDialog;
    delete ui;
}

/**
 * @brief Shows the addResourceToClientDialog
 */
void AddClientDialog::addResources()
{
    if (ui->resourcesTableView->model() != nullptr)
    {
        delete ui->resourcesTableView->model();
    }

    resourceDialog->show();
}


/**
 * @brief Checks the form before submiting it to the database
 */
void AddClientDialog::checkBeforeSubmit()
{
    if (ui->nameLineEdit->text().length() == 0 || ui->firstNameLineEdit->text().length() == 0
            || ui->addressLineEdit->text().length() == 0 || ui->cityLineEdit->text().length() == 0) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_COMPULSORY_INPUT);
        return;
    }
    if (ui->postalCodeLineEdit->text().length() < 5) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_CODE_POSTAL_INPUT);
        return;
    }
    if (ui->phoneNumLineEdit->text().length() > 0 && ui->phoneNumLineEdit->text().length() < 10) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_PHONE_NUMBER_INPUT);
        return;
    }

    //Question 4
    QString clientComments = ui->commentTextEdit->toPlainText() + "\n\n" + ui->diverseTextEdit->toPlainText();

    Client client(ui->nameLineEdit->text(),
                  ui->firstNameLineEdit->text(),
                  ui->addressLineEdit->text(),
                  ui->cityLineEdit->text(),
                  ui->postalCodeLineEdit->text().toInt(),
                  clientComments,                           //Question 4
                  ui->phoneNumLineEdit->text().toInt(),
                  ui->appointmentDayCalendar->selectedDate(),
                  ui->rdvDurationSpinBox->value(),
                  ui->prioritySpinBox->value(),
                  QList<Resource>()
                  );

    QStandardItemModel * model;

    QList<Resource> resources;

    if (ui->resourcesTableView->model() != nullptr)
    {
        model = static_cast<QStandardItemModel*>(ui->resourcesTableView->model());
    }
    else
    {
        model = new QStandardItemModel(this);
    }

    for (int row = 0; row < model->rowCount(); row++)
    {
        Resource newResource(
                    model->index(row, 1).data().toString(),
                    model->index(row, 2).data().toString(),
                    model->index(row, 3).data().toString(),
                    model->index(row, 0).data().toInt()
                    );

        resources << newResource;
    }

    client.setResources(resources);

    if (mIdClient == -1)
    {
        DBManager::addClient(client);

        emit clientAdded();
    }
    else
    {
        DBManager::editClient(client);
    }

    accept();
}


/**
 * @brief Gets new resources for the client
 * @param resources The new resources
 */
void AddClientDialog::getNewResources(QList<Resource> resources)
{
    // Removes the duplicates
    QStandardItemModel * model;

    if (ui->resourcesTableView->model() != nullptr)
    {
        model = static_cast<QStandardItemModel*>(ui->resourcesTableView->model());
    }
    else
    {
        model = new QStandardItemModel(this);
    }

    for (int row = 0; row < model->rowCount(); row++)
    {
        Resource newResource(
                    model->index(row, 1).data().toString(),
                    model->index(row, 2).data().toString(),
                    model->index(row, 3).data().toString(),
                    model->index(row, 0).data().toInt()
                    );

        resources << newResource;
    }

    resources = resources.toSet().toList();

    model->clear();

    QStandardItem * root = model->invisibleRootItem();

    unsigned int row = root->rowCount();

    for (const Resource & resource : resources)
    {
        QStandardItem * idItem =
                new QStandardItem((QString::number(resource.getId())));

        QStandardItem * lastNameItem =
                new QStandardItem(resource.getLastName());

        QStandardItem * firstNameItem =
                new QStandardItem(resource.getFirstName());

        QStandardItem * typeItem =
                new QStandardItem(resource.getResourceType());

        model->setItem(row, 0, idItem);
        model->setItem(row, 1, lastNameItem);
        model->setItem(row, 2, firstNameItem);
        model->setItem(row, 3, typeItem);

        row++;
    }

    ui->resourcesTableView->setModel(model);
}

