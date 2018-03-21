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
    static QSqlQueryModel * getRessourcesModel();

<<<<<<< HEAD
    static void addClient(const Client & client);
    static void addRessource(const Resource & resource);
=======
    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);
>>>>>>> origin/master

private:

};

#endif // DBMANAGER_H
