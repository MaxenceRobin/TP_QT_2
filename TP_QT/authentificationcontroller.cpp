#include "authentificationcontroller.h"

AuthentificationController::AuthentificationController()
    : login(""), password("")
{
}

bool AuthentificationController::checkAuthentification(QString log, QString pswd)
{
    if (log.toStdString() == login && pswd.toStdString() == password)
        return true;
    return false;
}
