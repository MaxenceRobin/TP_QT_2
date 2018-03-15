#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "client.h"

#include <QSqlQueryModel>

class DBManager
{
public:
    DBManager();

    static QSqlQueryModel * getClientsModel();

private:

};

#endif // DBMANAGER_H
