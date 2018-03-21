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
