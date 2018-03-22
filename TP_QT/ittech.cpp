#include "ittech.h"

/**
 * @brief The QString to use to define a resource as an IT Technician
 */
const QString ITTech::RESOURCE_TYPE_IT_TECH = "Informaticien";

/**
 * @brief Default constructor
 */
ITTech::ITTech()
    : Resource()
{
    setResourceType(RESOURCE_TYPE_IT_TECH);
}


/**
 * @brief Parameter constructor to initialize an IT Technician
 * @param lastName IT Technician's last name
 * @param firstName IT Technician's first name
 * @param login IT Technician's login
 * @param password IT Technician's password
 */
ITTech::ITTech(const QString lastName, const QString firstName, const QString login, const QString password)
    : Resource(lastName, firstName, RESOURCE_TYPE_IT_TECH), mLogin(login), mPassword(password)
{
}
