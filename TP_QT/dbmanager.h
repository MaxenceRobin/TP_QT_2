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

    //Constants about the data index in the resourcesTypesModel
    static const int INDEX_TYPE_COL_RESOURCES_TYPES_MODEL;

    //Constants about the data index in the clientsModel
    static const int INDEX_ID_COL_CLIENTS_MODEL;
    static const int INDEX_LNAME_COL_CLIENTS_MODEL;
    static const int INDEX_FNAME_COL_CLIENTS_MODEL;
    static const int INDEX_DATE_COL_CLIENTS_MODEL;

    static QSqlQueryModel * getClientsModel();
    static QSqlQueryModel * getResourcesModel();
    static QSqlQueryModel * getResourcesTypesModel();

    static void addClient(const Client & client);
    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);

private:

};

#endif // DBMANAGER_H
