#include "staff.h"

Staff::Staff()
    : Person()
{

}

Staff::Staff(const QString lastName, const QString firstName, const QString staffType)
    : Person(lastName, firstName), mStaffType(staffType)
{
}
