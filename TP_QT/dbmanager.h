#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "client.h"
#include "resource.h"
#include "ittech.h"

#include <QSqlQueryModel>


class DBManager
{
private:
    static int getMaxId(QString tableName);
public:
    DBManager();

    static QSqlQueryModel * getClientsModel();
    static QSqlQueryModel * getResourcesModel();

    static void addClient(const Client & client);
    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);
<<<<<<< HEAD
=======

>>>>>>> origin/master

private:

};

#endif // DBMANAGER_H
