#ifndef SELFMANAGEDDATABASE_H
#define SELFMANAGEDDATABASE_H

#include <QSqlDatabase>

/**
 * @brief Class used to manage the database connexions
 */
class SelfManagedDatabase : public QSqlDatabase
{
public:
    SelfManagedDatabase();
    ~SelfManagedDatabase();
};

#endif // SELFMANAGEDDATABASE_H
