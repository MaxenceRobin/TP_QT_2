#include "dbmanager.h"

#include "selfmanageddatabase.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

DBManager::DBManager()
{
}

const int DBManager::INDEX_TYPE_COL_RESOURCES_TYPES_MODEL = 3;

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
                    "select * "
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
                    "select R.Id, R.Nom, R.Prenom, T.Label "
                    "from TRessource R, TType T "
                    "where R.IdType = T.Id"
                    );

        return model;
    }

    return new QSqlQueryModel;
}


QSqlQueryModel * DBManager::getResourcesTypesModel()
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQueryModel * model = new QSqlQueryModel;

        model->setQuery("SELECT Label FROM TType");
        return model;
    }

    return new QSqlQueryModel;
}


void DBManager::addClient(const Client & client)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery addClientQuery;

        addClientQuery.prepare(
                    "insert into TClient "
                    "(Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) "
                    "values "
                    "(:nom, :prenom, :adresse, :ville, :cp, :commentaire, :tel, :date, :duree, :priorite)"
                    );

        addClientQuery.bindValue(":nom", client.getLastName());
        addClientQuery.bindValue(":prenom", client.getFirstName());
        addClientQuery.bindValue(":adresse", client.getAddress());
        addClientQuery.bindValue(":ville", client.getCity());
        addClientQuery.bindValue(":cp", client.getPostalCode());
        addClientQuery.bindValue(":commentaire", client.getComment());
        addClientQuery.bindValue(":tel", client.getPhoneNumber());
        addClientQuery.bindValue(":date", client.getAppointmentDay());
        addClientQuery.bindValue(":duree", client.getAppointmentDuration());
        addClientQuery.bindValue(":priorite", client.getPriority());

        addClientQuery.exec();

        for (const Resource & resource : client.getResources())
        {
            unsigned int resourceId = resource.getId();

            QSqlQuery addRdvQuery;

            addRdvQuery.prepare(
                        "insert into TRdv "
                        "(IdClient, IdRessource) "
                        "values "
                        "(:client, :ressource)"
                        );

            addRdvQuery.bindValue(":client", client.getId());
            addRdvQuery.bindValue(":ressource", resourceId);

            addRdvQuery.exec();
        }
    }
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
        addAccountQuery.exec();
    }
}
