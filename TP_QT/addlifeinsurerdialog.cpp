#include "addlifeinsurerdialog.h"
#include "ui_addlifeinsurerdialog.h"
#include "resource.h"
#include "dbmanager.h"
#include <QMessageBox>

#define NAME_REG_EXP "[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*((-|\\s)[A-ZÀ-ÖØ-Ý][a-zà-öø-ÿ]*)*"

AddLifeInsurerDialog::AddLifeInsurerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLifeInsurerDialog)
{
    ui->setupUi(this);
    QRegExp nameRegExp(NAME_REG_EXP);
    QValidator * nameValidator = new QRegExpValidator(nameRegExp, this);
    ui->lastNameLineEdit->setValidator(nameValidator);
    ui->firstNameLineEdit->setValidator(nameValidator);
}

AddLifeInsurerDialog::~AddLifeInsurerDialog()
{
    delete ui;
}

/**
 * @brief Question 3
 */
void AddLifeInsurerDialog::on_addPushButton_clicked()
{
    if (!ui->lastNameLineEdit->text().isEmpty() && !ui->firstNameLineEdit->text().isEmpty())
    {
        Resource resource(ui->lastNameLineEdit->text(), ui->firstNameLineEdit->text(), "Assureur Vie");
        DBManager::addRessource(resource);
        accept();
    }
    else
    {
        QMessageBox::warning(this, "Avertissement", "Saisie incorrecte");
    }
}
