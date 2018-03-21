#include "resource.h"

Resource::Resource()
    : Person()
{

}

Resource::Resource(const QString lastName, const QString firstName, const QString resourceType)
    : Person(lastName, firstName), mResourceType(resourceType)
{
}
