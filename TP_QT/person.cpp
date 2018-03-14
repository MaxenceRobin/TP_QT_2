#include "person.h"

Person::Person()
    : mLastName(DEFAULT_NAME), mFirstName(DEFAULT_NAME)
{
}

Person::Person(const QString lastName, const QString firstName)
    :mLastName(lastName), mFirstName(firstName)
{
}
