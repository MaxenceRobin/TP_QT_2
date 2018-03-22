#include "resource.h"

/**
 * @brief Creates a default resource
 */
Resource::Resource()
    : Person(), mResourceType(DEFAULT_RESOURCE_TYPE)
{

}


/**
 * @brief Creates a resource
 * @param lastName The resource's last name
 * @param firstName The resource's first name
 * @param resourceType The resource's type
 * @param id The resource's id
 */
Resource::Resource(const QString lastName, const QString firstName, const QString resourceType, unsigned int id)
    : Person(lastName, firstName, id), mResourceType(resourceType)
{
}
