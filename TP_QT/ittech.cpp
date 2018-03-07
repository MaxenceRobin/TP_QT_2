#include "ittech.h"

ITTech::ITTech()
{
    StaffType type = itTech;
    setType(type);
}

ITTech::ITTech(const string lastName, const string firstName, const string login, const string password)
    : Staff(lastName, firstName, Staff::itTech), mLogin(login), mPassword(password)
{
}
