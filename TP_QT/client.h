#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"

#include <QDate>
#include <QString>


class Client : public Person
{
private:
    QString mAddress;
    QString mCity;
    unsigned int mPostalCode;
    unsigned int mPhoneNumber;
    QDate mAppointmentDay;
    unsigned int mAppointmentDuration;
    unsigned int mPriority;
    QString mComment;

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

    const QDate getAppointmentDay() const { return mAppointmentDay; }
    void setAppointDay(const QDate appointmentDay) { mAppointmentDay = appointmentDay; }

    unsigned int getAppiontmentDuration() const { return mAppointmentDuration; }
    void setAppointmentDuration(const unsigned int appointmentDuration) { mAppointmentDuration = appointmentDuration; }

    unsigned int getPriority() const { return mPriority; }
    void setPriority(const unsigned int priority) { mPriority = priority; }

    const QString & getComment() const { return mComment; }
    void setComment(const QString & comment) { mComment = comment; }
};

#endif // CLIENT_H
