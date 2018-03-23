#include "client.h"

Client::Client()
    :Person()
{
}


/**
 * @brief Constructs a client
 * @param lastName His/her last name
 * @param firstName His/her first name
 * @param address His/her address
 * @param city His/her city
 * @param postalCode His/her postal code
 * @param comment His/her comment
 * @param phoneNumber His/her phone number
 * @param appointmentDay His/her appointment date
 * @param appointmentDuration His/her appointment duration
 * @param priority His/her appointment priority
 * @param resources His/her resources for the appointment
 * @param id His/her ID
 */
Client::Client(const QString lastName, const QString firstName, const QString address,
               const QString city, const int postalCode, const QString &comment,
               const unsigned int phoneNumber, const QDate &appointmentDay,
               const unsigned int appointmentDuration, const unsigned int priority,
               const QList<Resource> &resources, unsigned int id)
    : Person(lastName, firstName, id), mAddress(address), mCity(city), mPostalCode(postalCode),
      mComment(comment), mPhoneNumber(phoneNumber), mAppointmentDay(appointmentDay),
      mAppointmentDuration(appointmentDuration), mPriority(priority), mResources(resources)
{
}
