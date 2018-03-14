#ifndef ITTECH_H
#define ITTECH_H
#include "staff.h"
#include <stdexcept>

#define STAFF_TYPE_IT_TECH "Informaticien"

class ITTech : public Staff
{
private:
    QString mLogin;
    QString mPassword;

public:
    //Constructors
    ITTech();
    ITTech(const QString lastName, const QString firstName, const QString login, const QString password);

    //Accessors
    const QString getLogin() const { return mLogin; }
    void setLogin(const QString login) { mLogin = login; }

    void setPassword(const QString password) { mPassword = password; }
    bool checkPassword(const QString password) const { return mPassword.compare(password); }

};

#endif // ITTECH_H
