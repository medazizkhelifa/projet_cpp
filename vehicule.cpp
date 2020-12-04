#include "vehicule.h"

vehicule::vehicule()
{

}

vehicule::vehicule(int idvehicule, QString destination, int id_employee, int id_stock, QDate datee)
{
    this->idvehicule=idvehicule;
    this->destination=destination;
    this->id_employee=id_employee;
    this->id_stock=id_stock;

    this->datee=datee;
}

bool vehicule::ajouter()
{
        QSqlQuery query;
        query.prepare("INSERT INTO VEHICULE (IDVEHICULE, DESTINATION, ID_EMPLOYEE,ID_STOCK,DATEE) "
                            "VALUES (:idvehicule, :destination, :id_employee,:id_stock,:datee)");
        query.bindValue(":idvehicule", idvehicule);
        query.bindValue(":destination", destination);
        query.bindValue(":id_employee", id_employee);
        query.bindValue(":id_stock", id_stock);

        query.bindValue(":datee", datee);
        return    query.exec();
}

QSqlQueryModel *vehicule::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from VEHICULE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID EMPLOYEE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID STOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

bool vehicule::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE VEHICULE SET DESTINATION=:destination, ID_EMPLOYEE=:id_employee,ID_STOCK=:id_stock,DATEE=:datee "
                        "WHERE IDVEHICULE=:idvehicule");
    query.bindValue(":idvehicule", idvehicule);
    query.bindValue(":destination", destination);
    query.bindValue(":id_employee", id_employee);
    query.bindValue(":id_stock", id_stock);
    query.bindValue(":datee", datee);
    return    query.exec();
}

bool vehicule::supprimer()
{
    QSqlQuery query;
    query.prepare("DELETE FROM VEHICULE WHERE IDVEHICULE=:idvehicule");
    query.bindValue(":idvehicule", idvehicule);
    return    query.exec();
}

QSqlQueryModel *vehicule::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from VEHICULE " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID EMPLOYEE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID STOCK"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEE"));
    return model;
}

QSqlQueryModel *vehicule::getIDs()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from VEHICULE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    return model;
}
