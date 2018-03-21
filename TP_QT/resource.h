#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include <map>
#include <QString>


class Resource : public Person
{
private:
    QString mResourceType;
public:
    //Constructors
    Resource();
    Resource(const QString lastName, const QString firstName, const QString staffType);

    //Accessors
    const QString getStaffType() const { return mResourceType; }
    void setStaffType(const QString staffType) { mResourceType = staffType; }
};

#endif // STAFF_H
