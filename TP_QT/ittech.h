#ifndef ITTECH_H
#define ITTECH_H
#include "resource.h"
#include <stdexcept>


class ITTech : public Resource
{
private:
    QString mLogin;
    QString mPassword;

public:
    static const QString RESOURCE_TYPE_IT_TECH;
    //Constructors
    ITTech();
    ITTech(const QString lastName, const QString firstName, const QString login, const QString password);

    //Accessors
    const QString getLogin() const { return mLogin; }
    void setLogin(const QString login) { mLogin = login; }

    const QString getPassword() const { return mPassword; }
    void setPassword(const QString password) { mPassword = password; }
    bool checkPassword(const QString password) const { return mPassword.compare(password); }
};

#endif // ITTECH_H
