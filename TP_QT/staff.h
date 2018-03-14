#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include "stafftype.h"
#include <map>
#include <QString>


class Staff : public Person
{
private:
    StaffType * mStaffType;

public:
    //Constructors
    Staff();
    Staff(const string lastName, const string firstName, StaffType * staffType);

    //Accessors
    StaffType * getType() const { return mStaffType; }
    void setType(StaffType * type) { mStaffType = type; }
};

#endif // STAFF_H
