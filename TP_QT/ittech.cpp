#include "ittech.h"

const QString ITTech::STAFF_TYPE_IT_TECH = "Informaticien";

ITTech::ITTech()
    : Resource()
{
    setStaffType(STAFF_TYPE_IT_TECH);
}

ITTech::ITTech(const QString lastName, const QString firstName, const QString login, const QString password)
    : Resource(lastName, firstName, STAFF_TYPE_IT_TECH), mLogin(login), mPassword(password)
{
}
