#include "client.h"

Client::Client()
{
}

Client::Client(const QString lastName, const QString firstName, const QString address,
               const QString city, const int postalCode, const int phoneNumber)
    : Person(lastName, firstName), mAddress(address), mCity(city),
      mPostalCode(postalCode), mPhoneNumber(phoneNumber)
{
}
