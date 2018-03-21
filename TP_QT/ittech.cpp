#include "ittech.h"

const QString ITTech::RESOURCE_TYPE_IT_TECH = "Informaticien";

ITTech::ITTech()
    : Resource()
{
    setStaffType(RESOURCE_TYPE_IT_TECH);
}

ITTech::ITTech(const QString lastName, const QString firstName, const QString login, const QString password)
    : Resource(lastName, firstName, RESOURCE_TYPE_IT_TECH), mLogin(login), mPassword(password)
{
}
