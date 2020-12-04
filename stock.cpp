#include "stock.h"

stock::stock()
{

}

stock::stock(int id, QString id_stocks, QString date_ajout, int id_vehicule,QString date_de_livraison)
{
    this->id=id;
    this->id_stocks=id_stocks;
    this->date_ajout=date_ajout;
    this->id_vehicule=id_vehicule;
    this->date_de_livraison=date_de_livraison;
}

bool stock::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO STOCK (ID, ID_STOCKS, DATE_AJOUT,ID_VEHICULE,DATE_DE_LIVRAISON) "
                        "VALUES (:id, :id_stocks, :date_ajout,:id_vehicule,:date_de_livraison)");
    query.bindValue(":id", id);
    query.bindValue(":id_stocks", id_stocks);
    query.bindValue(":date_ajout", date_ajout);
    query.bindValue(":id_vehicule", id_vehicule);
    query.bindValue(":date_de_livraison", date_de_livraison);
    return    query.exec();
}

QSqlQueryModel *stock::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,ID_STOCKS,DATE_AJOUT,ID_VEHICULE,DATE_DE_LIVRAISON from STOCK");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_STOCKS "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE AJOUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID VEHICULE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DE_LIVRAISON"));
    return model;
}

bool stock::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE STOCK SET ID_STOCKS=:id_stocks, DATE_AJOUT=:date_ajout, ID_VEHICULE=:id_vehicule , date_de_livraison=:date_de_livraison "
                        "WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":id_stocks", id_stocks);
    query.bindValue(":date_ajout", date_ajout);
    query.bindValue(":id_vehicule", id_vehicule);
    query.bindValue(":date_de_livraison", date_de_livraison);
    return    query.exec();
}

bool stock::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM STOCK "
                        "WHERE ID=:id");
    query.bindValue(":id", id);

    return    query.exec();
}

QSqlQueryModel *stock::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID,ID_STOCKS,DATE_AJOUT,ID_VEHICULE,DATE_DE_LIVRAISON from stock "+cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_STOCKS "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_ajout"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID VEHICULE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_DE_LIVRAISON"));
    return model;
}

QSqlQueryModel *stock::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from STOCK");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
