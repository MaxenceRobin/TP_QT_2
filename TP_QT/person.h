#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;

#define DEFAULT_NAME "none"


class Person
{
private:
    QString mLastName;
    QString mFirstName;
public:
    Person();
    Person(const QString lastName, const QString firstName);

    const QString getLastName() const { return mLastName; }
    void setLastName(const QString lastName) { mLastName = lastName; }

    const QString getFirstName() const { return mFirstName; }
    void setFirstName(const QString firstName) { mFirstName = firstName; }
};

#endif // PERSON_H
