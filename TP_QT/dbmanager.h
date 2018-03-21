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

    static void addClient(const Client & client);
    static void addRessource(const Resource & resource);

private:

};

#endif // DBMANAGER_H
