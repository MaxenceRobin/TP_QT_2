#include "client.h"

Client::Client()
{
}

Client::Client(const QString lastName, const QString firstName, const QString address,
               const QString city, const int postalCode, const QString &comment,
               const unsigned int phoneNumber, const QDate &appointmentDay,
               const unsigned int appointmentDuration, const unsigned int priority,
               const QList<Resource> &resources)
    : Person(lastName, firstName), mAddress(address), mCity(city), mPostalCode(postalCode),
      mComment(comment), mPhoneNumber(phoneNumber), mAppointmentDay(appointmentDay),
      mAppointmentDuration(appointmentDuration), mPriority(priority), mResources(resources)
{
}
