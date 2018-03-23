#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "client.h"
#include "resource.h"
#include "ittech.h"

#include <QSqlQueryModel>
#include <QStandardItemModel>


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
    static QStandardItemModel * getNestedResourcesModel();
    static Resource getResourceById(unsigned int id);
    static Client getClientById(unsigned int id);

    static void addClient(const Client & client);
    static void addRessource(const Resource &resource);
    static void addITTech(const ITTech &itTech);
    static bool checkAccount(const QString login, const QString password);


    static void editClient(const Client & client);
    static void editResource(const Resource &resource);
    static void editITTech(const ITTech & resource);
    static void deleteResource(const Resource &resource);
    static void deleteClient(unsigned int clientId);

private:

};

#endif // DBMANAGER_H
