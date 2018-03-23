#include "logindialog.h"
#include "ui_logindialog.h"
#include "qmessagebox.h"
#include "dbmanager.h"

/**
 * @brief Constructs the login dialog
 * @param parent
 */
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

/**
 * @brief Connects the user to the software
 */
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

/**
 * @brief Checks that the account exists on the database
 * @return True if it exists, false else
 */
bool LoginDialog:: checkLogin()
{
    return DBManager::checkAccount(ui->loginLineEditI->text(), ui->passwordLineEdit->text());
}
