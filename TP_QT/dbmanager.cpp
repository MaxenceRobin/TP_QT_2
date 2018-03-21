#include "dbmanager.h"

#include "selfmanageddatabase.h"

#include <QSqlQuery>
#include <QDebug>

DBManager::DBManager()
{
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

QSqlQueryModel * DBManager::getRessourcesModel()
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


