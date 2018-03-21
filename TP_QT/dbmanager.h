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

    static const int INDEX_TYPE_COL_RESOURCES_TYPES_MODEL;

    static QSqlQueryModel * getClientsModel();
    static QSqlQueryModel * getResourcesModel();
    static QSqlQueryModel * getResourcesTypesModel();

    static void addClient(const Client & client);
    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);

private:

};

#endif // DBMANAGER_H
