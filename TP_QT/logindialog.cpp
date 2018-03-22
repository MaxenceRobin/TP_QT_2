#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"
#include "dbmanager.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(sizeHint());
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::connect()
{
    if (checkLogin())
        accept();
    else
    {
        ui->passwordLineEdit->clear();
        QMessageBox::warning(this, "Avertissement", "Identifiant et/ou mot de passe incorrect(s)");
    }
}


bool LoginDialog:: checkLogin()
{
    return DBManager::checkAccount(ui->loginLineEditI->text(), ui->passwordLineEdit->text());
}
