#include "person.h"

Person::Person()
    : mLastName(DEFAULT_NAME), mFirstName(DEFAULT_NAME)
{
}

Person::Person(const string lastName, const string firstName)
    :mLastName(lastName), mFirstName(firstName)
{
}
