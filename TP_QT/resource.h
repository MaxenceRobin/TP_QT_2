#ifndef STAFF_H
#define STAFF_H
#include "person.h"
#include <map>
#include <QString>

#define DEFAULT_RESOURCE_TYPE "Divers"

/**
 * @brief The Resource class used to define a resource as a person with a resource type
 * @see Person
 */
class Resource : public Person
{
private:
    QString mResourceType;
public:
    //Constructors
    Resource();
    Resource(const QString lastName, const QString firstName, const QString staffType, unsigned int id = -1);

    /**
     * @return The resource type
     */
    const QString getResourceType() const { return mResourceType; }
    /**
     * @brief Sets the new resource type
     * @param staffType The new resource type
     */
    void setResourceType(const QString resourceType) { mResourceType = resourceType; }
};

inline bool operator==(const Resource & first, const Resource & second)
{
    return first.getId() == second.getId();
}

inline uint qHash(const Resource & resource)
{
    return resource.getId();
}

#endif // STAFF_H
