#include "addstaffdialog.h"
#include "ui_addstaffdialog.h"
#include "qmessagebox.h"
#include "staff.h"

//Regular expression to control inputs
#define NAME_REG_EXP "[A-Z][a-z]*((-|\\s)[A-Z][a-z]*)*"

//Input error messages
#define ERROR_MSG_COMPULSORY_INPUT "Tous les champs obligatoires (*) doivent être complétés"

AddStaffDialog::AddStaffDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStaffDialog)
{
    ui->setupUi(this);

    //Checks the input of a correct name
    QRegExp nameRegExp(NAME_REG_EXP);
    QValidator * nameValidator = new QRegExpValidator(nameRegExp, this);
    ui->nameLineEdit->setValidator(nameValidator);
    ui->firstNameLineEdit->setValidator(nameValidator);

    //for (int i = 0; i < Staff::NBR_OF_STAFF_TYPES; i++)
        //ui->typeComboBox->addItem(Staff::STRINGS_FROM_STAFF_TYPES[i]);

    ui->typeComboBox->setCurrentIndex(0);
    on_typeComboBox_currentIndexChanged(ui->typeComboBox->currentIndex());
}


void AddStaffDialog::checkBeforeSubmit()
{
    if (ui->nameLineEdit->text().length() == 0 || ui->firstNameLineEdit->text().length() == 0) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_COMPULSORY_INPUT);
        return;
    }

    /*if (ui->typeComboBox->currentIndex() == Staff::itTech
            && (ui->loginLineEdit->text().length() == 0 || ui->passwordLineEdit->text().length() == 0)) {
        QMessageBox::warning(this, "Avertissement", ERROR_MSG_COMPULSORY_INPUT);
        return;
    }*/

    accept();
}

void AddStaffDialog::on_typeComboBox_currentIndexChanged(int index)
{
    /*if (index == Staff::itTech) {
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
    }*/
}


AddStaffDialog::~AddStaffDialog()
{
    delete ui;
}

