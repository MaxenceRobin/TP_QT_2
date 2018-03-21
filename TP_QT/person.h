#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;

#define DEFAULT_NAME "none"


class Person
{
private:
    unsigned int mId;
    QString mLastName;
    QString mFirstName;
public:
    Person();
    Person(const QString lastName, const QString firstName);

    unsigned int getId() const { return mId; }
    void setId(unsigned int id) { mId = id; }

    const QString getLastName() const { return mLastName; }
    void setLastName(const QString lastName) { mLastName = lastName; }

    const QString getFirstName() const { return mFirstName; }
    void setFirstName(const QString firstName) { mFirstName = firstName; }
};

#endif // PERSON_H
