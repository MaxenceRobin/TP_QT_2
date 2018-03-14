#include "ittech.h"

ITTech::ITTech()
    : Staff()
{
    setStaffType(STAFF_TYPE_IT_TECH);
}

ITTech::ITTech(const string lastName, const string firstName, const string login, const string password)
    : Staff(lastName, firstName, STAFF_TYPE_IT_TECH), mLogin(login), mPassword(password)
{
}
