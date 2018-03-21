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

<<<<<<< HEAD
    static void addResource(const Resource &resource);
=======
<<<<<<< HEAD
    static void addClient(const Client & client);
    static void addRessource(const Resource & resource);
=======
    static void addRessource(const Resource &resource);
>>>>>>> 8afc3267a471bd2e3df23e56844abd792ea71150
    static void addITTech(const ITTech &itTech);
>>>>>>> origin/master

private:

};

#endif // DBMANAGER_H
