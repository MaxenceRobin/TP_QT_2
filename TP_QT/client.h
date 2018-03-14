#ifndef CLIENT_H
#define CLIENT_H
#include "person.h"


class Client : public Person
{
private:
    QString mAddress;
    QString mCity;
    int mPostalCode;
    int mPhoneNumber;

public:
    //Constructors
    Client();
    Client(const QString lastName, const QString firstName, const QString address,
           const QString city, const int postalCode, const int phoneNumber);

    //Accessors
    const QString getAddress() const { return mAddress; }
    void setAddress(const QString address) { mAddress = address; }

    const QString getCity() const { return mCity; }
    void setCity(const QString city) { mCity = city; }

    const int getPostalCode() { return mPostalCode; }
    void setPostalCode(const int postalCode) { mPostalCode = postalCode; }
};

#endif // CLIENT_H
