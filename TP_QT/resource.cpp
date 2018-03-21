#include "resource.h"

Resource::Resource()
    : Person()
{

}

Resource::Resource(const QString lastName, const QString firstName, const QString staffType)
    : Person(lastName, firstName), mStaffType(staffType)
{
}
