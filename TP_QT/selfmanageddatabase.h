#ifndef SELFMANAGEDDATABASE_H
#define SELFMANAGEDDATABASE_H

#include <QSqlDatabase>

class SelfManagedDatabase : public QSqlDatabase
{
public:
    SelfManagedDatabase();
    ~SelfManagedDatabase();
};

#endif // SELFMANAGEDDATABASE_H
