#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include <map>
#include <QString>


class Staff : public Person
{
private:
    string mStaffType;
public:
    //Constructors
    Staff();
    Staff(const string lastName, const string firstName, const string staffType);

    //Accessors
    const string getStaffType() const { return mStaffType; }
    void setStaffType(const string staffType) { mStaffType = staffType; }
};

#endif // STAFF_H
