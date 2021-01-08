#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Produit
{public:
    Produit();
    Produit(int,int,int,int,int,int);
    int get_idp();
    int get_idf();
    int get_ids();
    int get_eval();
    int get_prix();
    int get_poids();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichertri1();
    QSqlQueryModel * affichertri1_1();
    QSqlQueryModel * affichertri2();
    QSqlQueryModel * affichertri2_1();
    QSqlQueryModel * affichertri3();
    QSqlQueryModel * affichertri3_1();
    QSqlQueryModel * affichertri4();
    QSqlQueryModel * affichertri4_1();
    QSqlQueryModel * affichertri5();
    QSqlQueryModel * affichertri5_1();
    QSqlQueryModel * affichertri6();
    QSqlQueryModel * affichertri6_1();
    QSqlQueryModel * recherche(int);

    bool supprimer(int);
    bool modifier(int);
private:
    int id_produit , id_fournisseur, id_stock, evaluation, prix, poids;
};

#endif // PRODUIT_H
