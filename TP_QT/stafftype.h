#ifndef STAFFTYPE_H
#define STAFFTYPE_H
#include <string>
using namespace std;


class StaffType
{
private:
    string mType;
public:
    StaffType(const string type) { mType = type; }

    const string getType() const { return mType; }
    void setType(const string type) { mType = type; }
};

#endif // STAFFTYPE_H
