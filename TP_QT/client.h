#ifndef CLIENT_H
#define CLIENT_H
#include "person.h"


class Client : public Person
{
private:
    string mAddress;
    string mCity;
    int mPostalCode;
    int mPhoneNumber;

public:
    //Constructors
    Client();
    Client(const string lastName, const string firstName, const string address,
           const string city, const int postalCode, const int phoneNumber);

    //Accessors
    const string getAddress() const { return mAddress; }
    void setAddress(const string address) { mAddress = address; }

    const string getCity() const { return mCity; }
    void setCity(const string city) { mCity = city; }

    const int getPostalCode() const { return mPostalCode; }
    void setPostalCode(const int postalCode) { mPostalCode = postalCode; }
};

#endif // CLIENT_H
