#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

#define DEFAULT_NAME "none"


class Person
{
private:
    string mLastName;
    string mFirstName;
public:
    Person();
    Person(const string lastName, const string firstName);

    const string getLastName() const { return mLastName; }
    void setLastName(const string lastName) { mLastName = lastName; }

    const string getFirstName() const { return mFirstName; }
    void setFirstName(const string firstName) { mFirstName = firstName; }
};

#endif // PERSON_H
