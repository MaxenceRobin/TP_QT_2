#include "resource.h"

Resource::Resource()
    : Person()
{

}

Resource::Resource(const QString lastName, const QString firstName, const QString resourceType, unsigned int id)
    : Person(lastName, firstName, id), mResourceType(resourceType)
{
}
