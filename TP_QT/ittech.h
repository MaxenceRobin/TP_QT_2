#ifndef ITTECH_H
#define ITTECH_H
#include "staff.h"
#include <stdexcept>

#define STAFF_TYPE_IT_TECH "Informaticien"

class ITTech : public Staff
{
private:
    string mLogin;
    string mPassword;

public:
    //Constructors
    ITTech();
    ITTech(const string lastName, const string firstName, const string login, const string password);

    //Accessors
    const string getLogin() const { return mLogin; }
    void setLogin(const string login) { mLogin = login; }

    void setPassword(const string password) { mPassword = password; }
    bool checkPassword(const string password) const { return mPassword.compare(password); }

};

#endif // ITTECH_H
