#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include <map>
#include <QString>


class Staff : public Person
{
private:
    QString mStaffType;
public:
    //Constructors
    Staff();
    Staff(const QString lastName, const QString firstName, const QString staffType);

    //Accessors
    const QString getStaffType() const { return mStaffType; }
    void setStaffType(const QString staffType) { mStaffType = staffType; }
};

#endif // STAFF_H
