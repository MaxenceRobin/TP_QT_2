#include "person.h"

/**
 * @brief Constructs a default person
 */
Person::Person()
    : mId(0), mLastName(DEFAULT_NAME), mFirstName(DEFAULT_NAME)
{
}


/**
 * @brief Constructs a person
 * @param lastName The person's last name
 * @param firstName The person's first name
 * @param id The person's id
 */
Person::Person(const QString lastName, const QString firstName, unsigned int id)
    : mId(id), mLastName(lastName), mFirstName(firstName)
{
}
