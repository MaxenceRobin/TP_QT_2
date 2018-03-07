#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include <map>
#include <QString>


class Staff : public Person
{
public:
    enum StaffType { bankerA,
                      bankerB,
                      housingInsurer,
                      carInsurer,
                      lifeInsurer,
                      itTech,
                      diverse };

    static const QString STRINGS_FROM_STAFF_TYPES[];
    static const int NBR_OF_STAFF_TYPES = 7;
private:
    StaffType mType;


public:
    //Constructors
    Staff();
    Staff(const string lastName, const string firstName, const StaffType type);

    //Accessors
    StaffType getType() const { return mType; }
    void setType(const StaffType type) { mType = type; }
};

#endif // STAFF_H
