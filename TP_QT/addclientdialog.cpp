#include "addclientdialog.h"
#include "ui_addclientdialog.h"
#include "qmessagebox.h"

//Regular expression to control inputs
#define NAME_REG_EXP "[A-Z][a-z]*((-|\\s)[A-Z][a-z]*)*"
#define FR_POSTAL_CODE_REG_EXP "[0-9]{5}"
#define FR_PHONE_NUMBER_REG_EXP "[0-9]{10}"

//Input error messages
#define ERROR_MSG_CODE_POSTAL_INPUT "Code postal incorrect - Doit être composé de 5 chiffres"
#define ERROR_MSG_PHONE_NUMBER_INPUT "Numéro de téléphone incorrect - Doit être composé de 10 chiffres"
#define ERROR_MSG_COMPULSORY_INPUT "Tous les champs obligatoires (*) doivent être complétés"


AddClientDialog::AddClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClientDialog)
{
    ui->setupUi(this);
    ui->calendarWidget->setSelectedDate(QDate::currentDate());
    ui->calendarWidget->setMinimumDate(QDate::currentDate());

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
}

AddClientDialog::~AddClientDialog()
{
    delete ui;
}

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
    if (ui->phoneNumLineEdit->text().length() < 10) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_PHONE_NUMBER_INPUT);
        return;
    }
    accept();
}
