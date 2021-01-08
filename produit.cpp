#include "produit.h"
#include <QDebug>
Produit::Produit()
{
 int id_produit=0;
         int id_fournisseur=0;
         int id_stock=0;
         int evaluation=0;
         int prix=0;
         int poids=0;
}
Produit::Produit( int id_produit , int id_fournisseur, int id_stock,int evaluation, int prix,int poids)
{
  this->id_produit=id_produit;
  this->id_fournisseur=id_fournisseur;
  this->id_stock=id_stock;
  this->evaluation=evaluation;
  this->prix=prix;
  this->poids=poids;
}
int Produit::get_idp(){return id_produit ;}
int Produit::get_idf(){return id_fournisseur;}
int Produit::get_ids(){return  id_stock;}
int Produit::get_eval(){return  evaluation;}
int Produit::get_prix(){return  prix;}
int Produit::get_poids(){return  poids;}

bool Produit::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO produit (id_produit, id_fournisseur, id_stock,evaluation,prix,poids) "
                    "VALUES (:id_produit, :id_fournisseur, :id_stock, :evaluation, :prix, :poids)");
query.bindValue(":id_produit", id_produit);
query.bindValue(":id_fournisseur", id_fournisseur);
query.bindValue(":id_stock", id_stock);
query.bindValue(":evaluation", evaluation);
query.bindValue(":prix", prix);
query.bindValue(":poids", poids);

return    query.exec();
}

QSqlQueryModel * Produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri1()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit order by ID_Produit  DESC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri1_1()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit order by ID_Produit  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri2()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by prix  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri2_1()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by Prix desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri3()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_STOCK   ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri3_1()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_STOCK desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri4()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by evaluation  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri4_1()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by evaluation desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri5()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_Fournisseur  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri5_1()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_Fournisseur desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri6()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_STOCK ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
QSqlQueryModel * Produit::affichertri6_1()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from produit order by ID_STOCK desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}


bool Produit::supprimer(int id_produit)
{
QSqlQuery query;

query.prepare("Delete from produit where id_produit = :id_produit ");
query.bindValue(":id_produit", id_produit);
return    query.exec();
}
bool Produit::modifier( int id_produit)
{
QSqlQuery query;


query.prepare("UPDATE PRODUIT SET id_produit=:id_produit, id_fournisseur=:id_fournisseur, id_stock=:id_stock , evaluation=:evaluation, prix=:prix, poids=:poids WHERE id_produit= :id_produit ");

query.bindValue(":id_produit", id_produit);
query.bindValue(":id_fournisseur", id_fournisseur);
query.bindValue(":id_stock", id_stock);
query.bindValue(":evaluation", evaluation);
query.bindValue(":prix", prix);
query.bindValue(":poids", poids);




return    query.exec();
}
QSqlQueryModel * Produit::recherche(int ID_produit)

   {

    QSqlQueryModel * model = new QSqlQueryModel() ;
    model->setQuery("Select * from produit where ID_produit = :ID_produit  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Fournisseu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Evaluation"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    return model;
}
