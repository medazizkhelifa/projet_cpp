#include "dialogproduit.h"
#include "ui_dialogproduit.h"
#include "dialogmenu.h"
#include "produit.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QMediaPlayer>

#include <QLabel>
#include <QPixmap>
dialogproduit::dialogproduit(QWidget *parent) :
     QDialog(parent),
    ui(new Ui::dialogproduit)
{
        player = new QMediaPlayer(this);

ui->setupUi(this);

 ui-> lineEdit_stock_2  ->hide();
/* ui-> nstock_la->hide();*/
 ui-> lineEdit_four1 ->hide();
 ui->lineEdit_eval2  ->hide();
 ui-> lineEdit_prix2 ->hide();
 ui->four2 ->hide();
 ui->evall ->hide();
 ui->label_11->hide();
 ui->label_12->hide();
 ui-> lineEdit_poids2	->hide();
  ui->four2_2  ->hide();

}

dialogproduit::~dialogproduit()
{
    delete ui;


}

void dialogproduit::on_pb_ajouter_clicked()
{
    int id_produit = ui->lineEdit_idprod1->text().toInt();
    int id_fournisseur= ui->lineEdit_four->text().toInt();
    int id_stock= ui->lineEdit_stock->text().toInt();
    int evaluation= ui->lineEdit_eval->text().toInt();
    int prix= ui->lineEdit_prix->text().toInt();
    int poids= ui->lineEdit_poids->text().toInt();
  Produit e(id_produit , id_fournisseur, id_stock, evaluation, prix, poids);
  bool test=e.ajouter();
  if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogproduit::on_pb_supprimer_clicked()
{
int id_produit = ui->lineEdit_idprod2->text().toInt();
bool test=tmpproduit.supprimer(id_produit);
if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                QObject::tr("Produit supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogproduit::on_tabWidget_currentChanged(int index)
{
    ui->tabproduit->setModel(tmpproduit.afficher());
}

void dialogproduit::on_pushButton_clicked()
{
 this->hide();
    dialogmenu d;
    d.exec();

}

void dialogproduit::on_pb_edit_clicked()
{ int id_produit=ui->lineEdit_idprod3->text().toInt();
         QSqlQuery query;
              query.prepare("SELECT * FROM PRODUIT WHERE id_produit= ? ");
              query.addBindValue(id_produit);

               query.exec();
                 if(query.next())
                 {


                     ui-> lineEdit_stock_2  ->show();
                     ui-> lineEdit_four1 ->show();
                     ui->lineEdit_eval2  ->show();
                     ui-> lineEdit_prix2 ->show();
                     ui->four2 ->show();
                     ui->evall ->show();
                     ui->label_11->show();
                     ui->label_12->show();
                     ui-> lineEdit_poids2->show();
                     ui->four2_2->show();



                     }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("EDIT"),
                                       QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);



}

void dialogproduit::on_pb_save_clicked()
{

    int id_produit = ui->lineEdit_idprod3  ->text().toInt();
    int id_fournisseur = ui->lineEdit_four1  ->text().toInt();
    int id_stock = ui->lineEdit_stock_2 ->text().toInt();
    int evaluation = ui->lineEdit_eval2  ->text().toInt();
    int prix = ui->lineEdit_prix2  ->text().toInt();
    int poids = ui->lineEdit_poids2	 ->text().toInt();


 Produit h(id_produit , id_fournisseur, id_stock, evaluation, prix, poids);
         bool test=h.modifier(id_produit);
  if(test)
{ui->tabproduit->setModel(tmpproduit.afficher());


QMessageBox::information(nullptr, QObject::tr("Modifier un Produit"),
                  QObject::tr("Produit modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
     { QMessageBox::critical(nullptr, QObject::tr("Modifier une Produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel); }
  ui-> lineEdit_four1 ->hide();
  ui->lineEdit_eval2  ->hide();
  ui-> lineEdit_prix2 ->hide();
  ui->four2 ->hide();
  ui->evall ->hide();
  ui->label_11->hide();
  ui->label_12->hide();
  ui-> lineEdit_poids2	->hide();
  ui-> lineEdit_stock_2  ->hide();
  ui->four2_2  ->hide();
  ui->lineEdit_idprod1->clear();

}

void dialogproduit::on_button_music_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/m2596/Desktop/Qt/song.mp3"));
    player->play();
    qDebug() << player ->errorString();
}

void dialogproduit::on_tri1_clicked()
{
 ui->tabproduit->setModel(tmpproduit.affichertri1());
 ui->tri1->hide();
 ui->tri1_1->show();

}

void dialogproduit::on_tri1_1_clicked()
{

    ui->tabproduit->setModel(tmpproduit.affichertri1_1());
    ui->tri1_1->hide();
    ui->tri1->show();
}






void dialogproduit::on_tri2_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri2());
    ui->tri2->hide();
    ui->tri2_1->show();

}



void dialogproduit::on_tri2_1_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri2_1());
    ui->tri2_1->hide();
    ui->tri2->show();
}


void dialogproduit::on_tri3_clicked()
{
 ui->tabproduit->setModel(tmpproduit.affichertri3());
 ui->tri3->hide();
 ui->tri3_1->show();
}

void dialogproduit::on_tri3_1_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri3_1());
    ui->tri3_1->hide();
    ui->tri3->show();
}

void dialogproduit::on_tri4_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri4());
    ui->tri4->hide();
    ui->tri4_1->show();
}
void dialogproduit::on_tri4_1_clicked()
{   ui->tri4_1->hide();
    ui->tabproduit->setModel(tmpproduit.affichertri4_1());
    ui->tri4->show();
}
void dialogproduit::on_tri5_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri5());
    ui->tri5->hide();
    ui->tri5_1->show();
}
void dialogproduit::on_tri5_1_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri5_1());
    ui->tri5_1->hide();
    ui->tri5->show();
}
void dialogproduit::on_tri6_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri6());
    ui->tri6->hide();
    ui->tri6_1->show();
}
void dialogproduit::on_tri6_1_clicked()
{
    ui->tabproduit->setModel(tmpproduit.affichertri6_1());
    ui->tri6_1->hide();
    ui->tri6->show();
}








/* void dialogproduit::on_pushButton_3_clicked()
{   int id_produit = ui->rech->text().toInt();

    bool test=tmpproduit.recherche(id_produit);
    if(test)
  {ui->tabproduit->setModel(tmpproduit.recherche(id_produit));//refresh


  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche ID"),
                    QObject::tr("Erreur ID NOT FOUND !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }

*/



void dialogproduit::on_rech_textChanged(const QString &arg1)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM produit WHERE ID_PRODUIT LIKE'"+arg1+"%' or ID_FOURNISSEUR LIKE'"+arg1+"%' or ID_STOCK LIKE'"+arg1+"%' or EVALUATION LIKE'"+arg1+"%' or PRIX LIKE'"+arg1+"%' or POIDS LIKE '"+arg1+"%'");
     query->exec();
     model->setQuery(*query);
     ui->tabproduit->setModel(model);

}
