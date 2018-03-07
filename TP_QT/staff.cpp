#include "staff.h"

const QString Staff::STRINGS_FROM_STAFF_TYPES[] = {"Banquier A",
                                              "Banquier B",
                                              "Assureur logement",
                                              "Assureur voiture",
                                              "Assureur vie",
                                              "Informaticien",
                                              "Divers"};

Staff::Staff()
{
}

Staff::Staff(const string lastName, const string firstName, const StaffType type)
    : Person(lastName, firstName), mType(type)
{
}
