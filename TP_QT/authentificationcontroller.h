#ifndef AUTHENTIFICATIONCONTROLLER_H
#define AUTHENTIFICATIONCONTROLLER_H
#include <string>
#include "qstring.h"
using namespace std;


class AuthentificationController
{
private:
    string login;
    string password;
public:
    AuthentificationController();
    bool checkAuthentification(QString log, QString pswd);
};

#endif // AUTHENTIFICATIONCONTROLLER_H
