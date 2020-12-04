#ifndef STOCK_CONTROLLER_H
#define STOCK_CONTROLLER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class stock
{
public:
    stock();
    stock(int id, QString id_stocks,QString date_ajout,int id_vehicule,QString date_de_livraison);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool modifier();
    bool supprimer();
    QSqlQueryModel *displayClause(QString cls);
    QSqlQueryModel *getIDs();
private:
    int id,id_vehicule;
    QString id_stocks,employee,date_ajout,date_de_livraison;

};

#endif // STOCK_CONTROLLER_H
