#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "resource.h"

#include <QDate>
#include <QString>


/**
 * @brief The Client class used to represent a client as a person with contact and appointment details
 */
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

    /**
     * @return The client's address
     */
    const QString & getAddress() const { return mAddress; }
    /**
     * @brief Sets the client's address
     * @param address The new client's address
     */
    void setAddress(const QString & address) { mAddress = address; }

    /**
     * @return The client's city
     */
    const QString & getCity() const { return mCity; }
    /**
     * @brief Sets the client's city
     * @param address The new client's city
     */
    void setCity(const QString & city) { mCity = city; }

    /**
     * @return The client's postal code
     */
    int getPostalCode() const { return mPostalCode; }
    /**
     * @brief Sets the client's postal code
     * @param address The new client's postal code
     */
    void setPostalCode(const int postalCode) { mPostalCode = postalCode; }

    /**
     * @return The client's phone number
     */
    unsigned int getPhoneNumber() const { return mPhoneNumber; }
    /**
     * @brief Sets the client's phone number
     * @param address The new client's phone number
     */
    void setPhoneNumber(unsigned int phoneNumber) { mPhoneNumber = phoneNumber; }

    /**
     * @return The client's appointment date
     */
    const QDate getAppointmentDay() const { return mAppointmentDay; }
    /**
     * @brief Sets the client's appointment date
     * @param address The new client's appointment date
     */
    void setAppointDay(const QDate appointmentDay) { mAppointmentDay = appointmentDay; }

    /**
     * @return The client's appointment duration in minutes
     */
    unsigned int getAppointmentDuration() const { return mAppointmentDuration; }
    /**
     * @brief Sets the client's appointment duration in minutes
     * @param address The new client's appointment duration in minutes
     */
    void setAppointmentDuration(const unsigned int appointmentDuration) { mAppointmentDuration = appointmentDuration; }

    /**
     * @return The client's appointment priority
     */
    unsigned int getPriority() const { return mPriority; }
    /**
     * @brief Sets the client's appointment priority
     * @param address The new client's appointment priority
     */
    void setPriority(const unsigned int priority) { mPriority = priority; }

    /**
     * @return The client's appointment comment
     */
    const QString & getComment() const { return mComment; }
    /**
     * @brief Sets the client's appointment comment
     * @param address The new client's appointment comment
     */
    void setComment(const QString & comment) { mComment = comment; }

    /**
     * @return The client's appointment resources list
     */
    const QList<Resource> & getResources() const { return mResources; }
    /**
     * @brief Sets the client's resources list
     * @param address The new client's resources list
     */
    void setResources(const QList<Resource> & resources) { mResources = resources; }
};

#endif // CLIENT_H
