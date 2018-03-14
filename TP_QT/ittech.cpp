#include "ittech.h"

ITTech::ITTech()
    : Staff()
{
    setStaffType(STAFF_TYPE_IT_TECH);
}

ITTech::ITTech(const QString lastName, const QString firstName, const QString login, const QString password)
    : Staff(lastName, firstName, STAFF_TYPE_IT_TECH), mLogin(login), mPassword(password)
{
}
