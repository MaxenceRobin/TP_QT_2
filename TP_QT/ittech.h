#ifndef ITTECH_H
#define ITTECH_H
#include "resource.h"
#include <stdexcept>


/**
 * @brief The ITTech class used to store an IT Technician
 */
class ITTech : public Resource
{
private:
    QString mLogin;
    QString mPassword;

public:
    static const QString RESOURCE_TYPE_IT_TECH;
    //Constructors
    ITTech();
    ITTech(const QString lastName, const QString firstName, const QString login, const QString password);

    /**
     * @return The IT Technician's login
     */
    const QString getLogin() const { return mLogin; }
    /**
     * @brief Sets the IT Technician's login
     * @param login The new IT Technician's login
     */
    void setLogin(const QString login) { mLogin = login; }

    /**
     * @return The IT Technician's password
     */
    const QString getPassword() const { return mPassword; }
    /**
     * @brief Sets the IT Technician's password
     * @param login The new IT Technician's password
     */
    void setPassword(const QString password) { mPassword = password; }
    bool checkPassword(const QString password) const { return mPassword.compare(password); }
};

#endif // ITTECH_H
