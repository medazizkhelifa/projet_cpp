#ifndef VEHICULE_H
#define VEHICULE_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class vehicule
{
public:
    vehicule();
    vehicule(int,QString,int,int,QDate);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int idvehicule;
    QString destination,employee;
    int id_employee,id_stocks,id_stock;
    QDate datee;
};

#endif // VEHICULE_H
