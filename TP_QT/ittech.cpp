#include "ittech.h"

ITTech::ITTech()
    : Staff()
{
    StaffType * type = new StaffType(STAFF_TYPE_IT_TECH);
    setType(type);
}

ITTech::ITTech(const string lastName, const string firstName, const string login, const string password)
    : Staff(lastName, firstName, new StaffType(STAFF_TYPE_IT_TECH)), mLogin(login), mPassword(password)
{
}
