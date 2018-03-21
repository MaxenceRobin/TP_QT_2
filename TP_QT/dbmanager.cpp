#include "dbmanager.h"

#include "selfmanageddatabase.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

DBManager::DBManager()
{
}


int DBManager::getMaxId(QString tableName)
{
    QString queryString = ("SELECT MAX(Id) FROM " + tableName);
    QSqlQuery query(queryString);
    query.first();
    qDebug() << query.lastError();
    return query.value(0).toInt();
}


QSqlQueryModel * DBManager::getClientsModel()
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQueryModel * model = new QSqlQueryModel;

        model->setQuery(
                    "select Nom, Prenom "
                    "from TClient"
                    );

        return model;
    }

    return new QSqlQueryModel;
}

QSqlQueryModel * DBManager::getResourcesModel()
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQueryModel * model = new QSqlQueryModel;

        model->setQuery(
                    "select R.Nom, R.Prenom, T.Label "
                    "from TRessource R, TType T "
                    "where R.IdType = T.Id"
                    );

        return model;
    }

    return new QSqlQueryModel;
}

void DBManager::addClient(const Client & client)
{
    SelfManagedDatabase database;
}


void DBManager::addRessource(const Resource &resource)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery getResourceTypeIdQuery;
        int resourceTypeId;
        getResourceTypeIdQuery.prepare(
                    "SELECT Id "
                    "FROM TType "
                    "WHERE Label = :label");
        getResourceTypeIdQuery.bindValue(":label", resource.getStaffType());
        getResourceTypeIdQuery.exec();
        getResourceTypeIdQuery.last();
        resourceTypeId = getResourceTypeIdQuery.value(0).toInt();


        QSqlQuery addResourceQuery;
        addResourceQuery.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) "
                                 "VALUES (:nom, :prenom, :idType)");
        addResourceQuery.bindValue(":nom", resource.getLastName());
        addResourceQuery.bindValue(":prenom", resource.getFirstName());
        addResourceQuery.bindValue(":idType", resourceTypeId);
        addResourceQuery.exec();
    }
}


void DBManager::addITTech(const ITTech &itTech)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery getResourceTypeIdQuery;
        int resourceTypeId;
        getResourceTypeIdQuery.prepare(
                    "SELECT Id "
                    "FROM TType "
                    "WHERE Label = :label");
        getResourceTypeIdQuery.bindValue(":label", ITTech::RESOURCE_TYPE_IT_TECH);
        getResourceTypeIdQuery.exec();
        getResourceTypeIdQuery.last();
        resourceTypeId = getResourceTypeIdQuery.value(0).toInt();

        QSqlQuery addResourceQuery;
        int resourceId;
        addResourceQuery.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) "
                                 "VALUES (:nom, :prenom, :idType)");
        addResourceQuery.bindValue(":nom", itTech.getLastName());
        addResourceQuery.bindValue(":prenom", itTech.getFirstName());
        addResourceQuery.bindValue(":idType", resourceTypeId);
        addResourceQuery.exec();
        resourceId = addResourceQuery.lastInsertId().toInt();

        QSqlQuery addAccountQuery;
        addAccountQuery.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) "
                                "VALUES (:idRessource, :login, :mdp)");
        addAccountQuery.bindValue(":idRessource", resourceId);
        addAccountQuery.bindValue(":login", itTech.getLogin());
        addAccountQuery.bindValue(":mdp", itTech.getPassword());
        addResourceQuery.exec();
    }
}
