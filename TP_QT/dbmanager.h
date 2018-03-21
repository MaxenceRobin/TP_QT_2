#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "client.h"
#include "resource.h"
#include "ittech.h"

#include <QSqlQueryModel>

class DBManager
{
public:
    DBManager();

    static QSqlQueryModel * getClientsModel();

    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);

private:

};

#endif // DBMANAGER_H
