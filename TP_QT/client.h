#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "resource.h"

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
    QList<Resource> mResources;

public:
    //Constructors
    Client();
    Client(const QString lastName, const QString firstName, const QString address,
           const QString city, const int postalCode, const QString & comment, const unsigned int phoneNumber,
           const QDate & appointmentDay, const unsigned int appointmentDuration, const unsigned int priority,
           const QList<Resource> & resources, unsigned int id = -1);

    //Accessors
    const QString & getAddress() const { return mAddress; }
    void setAddress(const QString & address) { mAddress = address; }

    const QString & getCity() const { return mCity; }
    void setCity(const QString & city) { mCity = city; }

    int getPostalCode() const { return mPostalCode; }
    void setPostalCode(const int postalCode) { mPostalCode = postalCode; }

    unsigned int getPhoneNumber() const { return mPhoneNumber; }
    void setPhoneNumber(unsigned int phoneNumber) { mPhoneNumber = phoneNumber; }

    const QDate getAppointmentDay() const { return mAppointmentDay; }
    void setAppointDay(const QDate appointmentDay) { mAppointmentDay = appointmentDay; }

    unsigned int getAppointmentDuration() const { return mAppointmentDuration; }
    void setAppointmentDuration(const unsigned int appointmentDuration) { mAppointmentDuration = appointmentDuration; }

    unsigned int getPriority() const { return mPriority; }
    void setPriority(const unsigned int priority) { mPriority = priority; }

    const QString & getComment() const { return mComment; }
    void setComment(const QString & comment) { mComment = comment; }

    const QList<Resource> & getResources() const { return mResources; }
    void setResources(const QList<Resource> & resources) { mResources = resources; }
};

#endif // CLIENT_H
