#include "vehicule.h"
#include <QDebug>

vehicule::vehicule()
{
id_vehicule=0;
destination="";
id_employer=0;
id_stock=0;
}
vehicule::vehicule(int id_vehicule, QString destination,int id_employer, int id_stock )
{
    this->id_vehicule=id_vehicule;
    this->destination=destination;
    this->id_employer=id_employer;
    this->id_stock=id_stock;

}
int vehicule::getid_vehicule(){return id_vehicule;}
QString vehicule::get_destination(){return destination;}
int vehicule::getid_employer(){return id_employer;}
int vehicule::getid_stock(){return id_stock;}

bool vehicule::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO vehicule (id_vehicule,destination,ID_EMPLOYER,ID_STOCK)"
                  "VALUES (:id_vehicule, :destination,:id_employer,:id_stock)");
    query.bindValue(":id_vehicule",id_vehicule);
    query.bindValue(":destination",destination);
    query.bindValue(":id_employer",id_employer);
    query.bindValue(":id_stock",id_stock);

    return query.exec();

}

QSqlQueryModel * vehicule::afficher()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher1()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher11()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_vehicule desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher2()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by destination");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher22()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by destination desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher3()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_employer");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher33()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_employer desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher4()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_stock desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
QSqlQueryModel * vehicule::afficher44()
{   QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule order by id_stock ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Destination"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Employer"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID Stock"));
    return model;
}
bool vehicule::supprimer(int id_vehicule)
{
    QSqlQuery query;
    query.prepare("Delete from vehicule where id_vehicule = :id_vehicule");
    query.bindValue(":id_vehicule", id_vehicule);
    return query.exec();
}
bool vehicule::modifier(int vehicule)
{
    QSqlQuery query;
    query.prepare("UPDATE vehicule SET id_vehicule=:id_vehicule, destination=:destination, id_employer=:id_employer,id_stock=:id_stock where id_vehicule=:id_vehicule");
    query.bindValue(":id_vehicule", id_vehicule);
    query.bindValue(":destination", destination);
    query.bindValue(":id_employer", id_employer);
    query.bindValue(":id_stock", id_stock);
    return query.exec();

}
