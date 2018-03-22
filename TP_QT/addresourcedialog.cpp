#include "addresourcedialog.h"
#include "ui_addresourcedialog.h"
#include "qmessagebox.h"
#include "resource.h"
#include "ittech.h"
#include "dbmanager.h"

//Regular expression to control inputs
#define NAME_REG_EXP "[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*((-|\\s)[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*)*"

//Input error messages
#define ERROR_MSG_COMPULSORY_INPUT "Tous les champs obligatoires (*) doivent être complétés"


AddResourceDialog::AddResourceDialog(UtilisationType type, QWidget *parent) :
    mType(type), QDialog(parent),
    ui(new Ui::AddResourceDialog)
{
    ui->setupUi(this);

    //Checks the input of a correct name
    QRegExp nameRegExp(NAME_REG_EXP);
    QValidator * nameValidator = new QRegExpValidator(nameRegExp, this);
    ui->nameLineEdit->setValidator(nameValidator);
    ui->firstNameLineEdit->setValidator(nameValidator);

    ui->typeComboBox->setModel(DBManager::getResourcesTypesModel());

    ui->typeComboBox->setCurrentIndex(0);
    on_typeComboBox_currentIndexChanged();
}


void AddResourceDialog::checkBeforeSubmit()
{
    if (ui->nameLineEdit->text().length() == 0 || ui->firstNameLineEdit->text().length() == 0) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_COMPULSORY_INPUT);
        return;
    }

    if (ui->typeComboBox->currentText() == ITTech::RESOURCE_TYPE_IT_TECH
            && (ui->loginLineEdit->text().length() == 0 || ui->passwordLineEdit->text().length() == 0)) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_COMPULSORY_INPUT);
        return;
    }

    if (ui->typeComboBox->currentText() == ITTech::RESOURCE_TYPE_IT_TECH) {
        ITTech itTech(ui->nameLineEdit->text(), ui->firstNameLineEdit->text(),
                      ui->loginLineEdit->text(), ui->passwordLineEdit->text());

        DBManager::addITTech(itTech);
    }
    else
    {
        Resource resource(ui->nameLineEdit->text(), ui->firstNameLineEdit->text(), ui->typeComboBox->currentText());

        DBManager::addRessource(resource);
    }

    accept();
}

void AddResourceDialog::on_typeComboBox_currentIndexChanged()
{
    if (ui->typeComboBox->currentText() == ITTech::RESOURCE_TYPE_IT_TECH)
    {
        ui->loginLineEdit->setEnabled(true);
        ui->passwordLineEdit->setEnabled(true);
        ui->loginLabel->setEnabled(true);
        ui->passwordLabel->setEnabled(true);
    }
    else
    {
        ui->loginLineEdit->setEnabled(false);
        ui->passwordLineEdit->setEnabled(false);
        ui->loginLabel->setEnabled(false);
        ui->passwordLabel->setEnabled(false);
    }
}


AddResourceDialog::~AddResourceDialog()
{
    if (ui->typeComboBox->model() != nullptr)
        delete ui->typeComboBox->model();
    delete ui;
}

