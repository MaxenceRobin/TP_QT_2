#include "selfmanageddatabase.h"

SelfManagedDatabase::SelfManagedDatabase()
    : QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))
{
    // Opening the database
    if (isValid())
    {
        setHostName("localhost");
        setUserName("root");
        setPassword("password");

        setDatabaseName("base_tmp.sqli");
        open();
    }
}

SelfManagedDatabase::~SelfManagedDatabase()
{
    // If the database was successfully opened, it has to be closed
    if (isOpen())
    {
        close();
        QSqlDatabase::removeDatabase(QSqlDatabase::database().connectionName());
        //QSqlDatabase::removeDatabase("QSQLITE");
    }
}
