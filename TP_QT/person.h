#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;

#define DEFAULT_NAME "none"

/**
 * @brief The Person class used to define a person with an Id, a last name and a first name
 */
class Person
{
private:
    unsigned int mId;
    QString mLastName;
    QString mFirstName;
public:
    Person();
    Person(const QString lastName, const QString firstName, unsigned int id = -1);

    //Accessors

    /**
     * @return the person's id
     */
    unsigned int getId() const { return mId; }
    /**
     * @brief Sets the person's id
     * @param id the new person's id
     */
    void setId(unsigned int id) { mId = id; }

    /**
     * @return The person's last name
     */
    const QString getLastName() const { return mLastName; }
    /**
     * @brief Sets the person's last name
     * @param lastName the new person's last name
     */
    void setLastName(const QString lastName) { mLastName = lastName; }

    /**
     * @return The person's first name
     */
    const QString getFirstName() const { return mFirstName; }
    /**
     * @brief Sets the person's first name
     * @param lastName the new person's first name
     */
    void setFirstName(const QString firstName) { mFirstName = firstName; }
};

#endif // PERSON_H
