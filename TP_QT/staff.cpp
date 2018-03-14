#include "staff.h"

Staff::Staff()
    : Person(), mStaffType(NULL)
{

}

Staff::Staff(const string lastName, const string firstName, StaffType * staffType)
    : Person(lastName, firstName), mStaffType(staffType)
{
}
