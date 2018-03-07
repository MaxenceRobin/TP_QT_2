#include "client.h"

Client::Client()
{
}

Client::Client(const string lastName, const string firstName, const string address,
               const string city, const int postalCode, const int phoneNumber)
    : Person(lastName, firstName), mAddress(address), mCity(city),
      mPostalCode(postalCode), mPhoneNumber(phoneNumber)
{
}
