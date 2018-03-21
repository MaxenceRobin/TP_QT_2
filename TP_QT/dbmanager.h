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
    static QSqlQueryModel * getResourcesModel();

    static void addResource(const Resource &resource);
    static void addITTech(const ITTech &itTech);

private:

};

#endif // DBMANAGER_H
