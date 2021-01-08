#ifndef VEHICULE_H
#define VEHICULE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class vehicule
{
public:
    vehicule();
    vehicule(int id_vehicule, QString destination, int id_employer,int id_stock);

    int getid_vehicule();
    QString get_destination();
    int getid_employer();
    int getid_stock();
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* afficher1();
    QSqlQueryModel* afficher11();
    QSqlQueryModel* afficher2();
    QSqlQueryModel* afficher22();
    QSqlQueryModel* afficher3();
    QSqlQueryModel* afficher33();
    QSqlQueryModel* afficher4();
    QSqlQueryModel* afficher44();
    QSqlQueryModel *recherche(int);
    bool supprimer(int);
    bool modifier(int);
private :
    int id_vehicule,id_employer,id_stock;
     QString destination;

};

#endif // VEHICULE_H
