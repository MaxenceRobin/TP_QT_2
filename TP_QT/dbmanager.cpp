#include "dbmanager.h"

#include "selfmanageddatabase.h"

#include <QSqlQuery>

DBManager::DBManager()
{
}

QSqlQueryModel * DBManager::getClientsModel()
{
    // Connection to the database
//    QSqlDatabase dataBase = QSqlDatabase::addDatabase("QSQLITE");

//    if (dataBase.isValid())
//    {
//        dataBase.setHostName("localhost");
//        dataBase.setUserName("root");
//        dataBase.setPassword("password");

////            if (QFile::exists("base_tmp.sqli"))
////                QFile::remove("base_tmp.sqli");

//        dataBase.setDatabaseName("base_tmp.sqli");
//        dataBase.open();

//        if (dataBase.isOpen())
//        {
//            QSqlQueryModel * model = new QSqlQueryModel;

//            model->setQuery("select id, nom, prenom from TClient");
//            model->setHeaderData(0, Qt::Horizontal, "Identifiant");
//            model->setHeaderData(1, Qt::Horizontal, "Nom");
//            model->setHeaderData(2, Qt::Horizontal, "Prénom");

//            dataBase.close();
//            dataBase.removeDatabase("QSQLITE");

//            return model;
//        }
//    }

    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQueryModel * model = new QSqlQueryModel;

        //model->setQuery("select id, nom, prenom from TClient");
        model->setQuery(QSqlQuery("select id, nom, prenom from TClient"));
        model->setHeaderData(0, Qt::Horizontal, "Identifiant");
        model->setHeaderData(1, Qt::Horizontal, "Nom");
        model->setHeaderData(2, Qt::Horizontal, "Prénom");

        return model;
    }

    return new QSqlQueryModel;
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
        while (getResourceTypeIdQuery.next())
            resourceTypeId = getResourceTypeIdQuery.value(0).toInt();


        QSqlQuery addResourceQuery;
        addResourceQuery.prepare("INSERT INTO TResource (Nom, Prenom, IdType) "
                                 "VALUES (:nom, :prenom, :idType)");
        addResourceQuery.bindValue(":nom", resource.getLastName());
        addResourceQuery.bindValue(":prenom", resource.getFirstName());
        addResourceQuery.bindValue(":idType", resourceTypeId);
        query.exec();
    }
}


void DBManager::addITTech(const ITTech &itTech)
{
    SelfManagedDatabase database;

    if (database.isOpen())
    {
        QSqlQuery getResourceTypeIdQuery;
        int resourceId;
        getResourceTypeIdQuery.prepare(
                    "SELECT Id "
                    "FROM TType "
                    "WHERE Label = :label");
        getResourceTypeIdQuery.bindValue(":label", ITTech::RESOURCE_TYPE_IT_TECH);
        while (getResourceTypeIdQuery.next())
            resourceTypeId = getResourceTypeIdQuery.value(0).toInt();

        QSqlQuery addResourceQuery;
        int resourceId;
        addResourceQuery.prepare("INSERT INTO TResource (Nom, Prenom, IdType) "
                                 "VALUES (:nom, :prenom, :idType)");
        addResourceQuery.bindValue(":nom", itTech.getLastName());
        addResourceQuery.bindValue(":prenom", itTech.getFirstName());
        addResourceQuery.bindValue(":idType", resourceTypeId);
        addResourceQuery.exec();
        resourceId = addResourceQuery.lastInsertId();

        QSqlQuery addAccountQuery;
        addAccountQuery.prepare("INSERT INTO TCompte (IdRessource, Login, MdP) "
                                "VALUES (:idRessource, :login, :mdp)");
        addAccountQuery.bindValue(":idRessource", resourceId);
        addAccountQuery.bindValue(":login", itTech.getLogin());
        addAccountQuery.bindValue(":mdp", itTech.getPassword());
        addResourceQuery.exec();
    }
}

