#include "dbmanager.h"

#include "selfmanageddatabase.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

DBManager::DBManager()
{
}

const int DBManager::INDEX_TYPE_COL_RESOURCES_TYPES_MODEL = 3;

const int DBManager::INDEX_ID_COL_CLIENTS_MODEL = 0;
const int DBManager::INDEX_LNAME_COL_CLIENTS_MODEL = 1;
const int DBManager::INDEX_FNAME_COL_CLIENTS_MODEL = 2;
const int DBManager::INDEX_DATE_COL_CLIENTS_MODEL = 8;

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

QStandardItemModel * DBManager::getNestedResourcesModel()
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QStandardItemModel * model = new QStandardItemModel;

        QStandardItem * root = model->invisibleRootItem();

        QSqlQuery getResourcesTypes;

        getResourcesTypes.prepare(
                    "select * "
                    "from TType"
                    );

        getResourcesTypes.exec();

        while (getResourcesTypes.next())
        {
            QStandardItem * typeItem = new QStandardItem(getResourcesTypes.value("Label").toString());
            const int id = getResourcesTypes.value("Id").toInt();

            root->appendRow(typeItem);

            QSqlQuery getStaffByType;

            getStaffByType.prepare(
                        "select R.Id, R.Nom, R.Prenom "
                        "from TRessource R "
                        "where R.IdType = :type"
                        );

            getStaffByType.bindValue(":type", id);
            getStaffByType.exec();

            while (getStaffByType.next())
            {
                QStandardItem * staffItem = new QStandardItem(
                            getStaffByType.value("Nom").toString() + " " +
                            getStaffByType.value("Prenom").toString());

                staffItem->setData(getStaffByType.value("Id").toInt());

                typeItem->appendRow(staffItem);
            }
        }

        return model;
    }

    return new QStandardItemModel;
}

Resource DBManager::getResourceById(unsigned int id)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery getResource;

        getResource.prepare(
                    "select * "
                    "from TRessource R, TType T "
                    "where R.Id = :id "
                    "and R.IdType = T.Id"
                    );

        getResource.bindValue(":id", id);

        getResource.exec();

        getResource.next();

        qDebug() << getResource.value("Nom").toString();

        Resource newResource(
                    getResource.value("Nom").toString(),
                    getResource.value("Prenom").toString(),
                    getResource.value("Label").toString(),
                    id
                    );

        qDebug() << newResource.getFirstName()
                 << newResource.getLastName()
                 << newResource.getResourceType();

        return newResource;
    }
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
        getResourceTypeIdQuery.bindValue(":label", resource.getResourceType());
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

void DBManager::editResource(const Resource & resource)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        // If an account link to this resource exist, is has to be removed
        QSqlQuery removeAccount;

        removeAccount.prepare(
                    "delete from TCompte "
                    "where IdRessource = :idres"
                    );

        removeAccount.bindValue(":idres", resource.getId());

        removeAccount.exec();

        QSqlQuery getTypeId;

        getTypeId.prepare(
                    "select Id "
                    "from TType "
                    "where Label = :label"
                    );

        getTypeId.bindValue(":label", resource.getResourceType());
        getTypeId.exec();

        getTypeId.next();

        const int idType = getTypeId.value("Id").toInt();

        QSqlQuery updateResource;

        updateResource.prepare(
                    "update TRessource "
                    "set "
                    "Nom = :nom, "
                    "Prenom = :prenom, "
                    "IdType = :idtype "
                    "where Id = :id"
                    );

        updateResource.bindValue(":nom", resource.getLastName());
        updateResource.bindValue(":prenom", resource.getFirstName());
        updateResource.bindValue(":idtype", idType);
        updateResource.bindValue(":id", resource.getId());

        updateResource.exec();
    }
}

/**
 * @brief Deletes the specified resource from the database
 * @param resource The resource to delete
 */
void DBManager::deleteResource(const Resource &resource)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        //Deletes the account if the resource is an IT Tehnician
        if (resource.getResourceType() == ITTech::RESOURCE_TYPE_IT_TECH)
        {
            QSqlQuery deleteAccountQuery;
            deleteAccountQuery.prepare("DELETE FROM TCompte WHERE IdRessource = :idRessource");
            deleteAccountQuery.bindValue(":idRessource", resource.getId());
            deleteAccountQuery.exec();
        }

        //Deletes the resource
        QSqlQuery deleteResourceQuery;
        deleteResourceQuery.prepare("DELETE FROM TRessource WHERE Id = :id");
        deleteResourceQuery.bindValue(":id", resource.getId());
        deleteResourceQuery.exec();
    }
}

void DBManager::editITTech(const ITTech & resource)
{
    editResource(resource);

    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery createAccount;

        createAccount.prepare(
                    "insert into TCompte "
                    "(IdRessource, Login, MdP) "
                    "values "
                    "(:idres, :login, :mdp)"
                    );

        createAccount.bindValue(":idres", resource.getId());
        createAccount.bindValue(":login", resource.getLogin());
        createAccount.bindValue(":mdp", resource.getPassword());

        createAccount.exec();
    }
}

/**
 * @brief Checks if the accout exists in the database
 * @param login The login
 * @param password The password
 * @return true if the accont exists, false else
 */
bool DBManager::checkAccount(const QString login, const QString password)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM TCompte "
                      "WHERE Login = :login AND MdP = :mdp");
        query.bindValue(":login", login);
        query.bindValue(":mdp", password);
        query.exec();
        if (query.first())
            return true;
    }
    return false;
}
