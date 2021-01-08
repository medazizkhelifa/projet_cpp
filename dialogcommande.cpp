#include "dialogcommande.h"
#include "ui_dialogcommande.h"
#include "ui_dialogmenu.h"
#include "commande.h"
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
#include <QWidget>
#include <QLabel>
#include <QPixmap>


dialogcommande::dialogcommande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogcommande)
{


ui->setupUi(this);

 ui-> lineEdit_stock_2  ->hide();
 ui-> lineEdit_four1 ->hide();
 ui->lineEdit_eval2  ->hide();
 ui-> lineEdit_prix2 ->hide();
 ui->four2 ->hide();
 ui->evall ->hide();
 ui->label_11->hide();

  ui->four2_2  ->hide();

}

dialogcommande::~dialogcommande()
{
    delete ui;


}

void dialogcommande::on_pb_ajouter_clicked()
{
    int id_commande = ui->lineEdit_idprod1->text().toInt();
    QString date_livraison= ui->lineEdit_four->text();
    QString destination= ui->lineEdit_stock->text();
    int id_produit= ui->lineEdit_eval->text().toInt();
    int id_client= ui->lineEdit_prix->text().toInt();

  Commande e(id_commande , date_livraison, destination, id_produit, id_client);
  bool test=e.ajouter();
  if(test)
{ui->tabproduit->setModel(tmpcmd.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Commande"),
                  QObject::tr("Commande ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajoute une Commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogcommande::on_pb_supprimer_clicked()
{
int id_commande = ui->lineEdit_idprod2->text().toInt();
bool test=tmpcmd.supprimer(id_commande);
if(test)
{ui->tabproduit->setModel(tmpcmd.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une Commande"),
                QObject::tr("Commande supprimée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une Commande"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogcommande::on_tabWidget_currentChanged(int index)
{
    ui->tabproduit->setModel(tmpcmd.afficher());
}

void dialogcommande::on_pushButton_clicked()
{

     this->hide();

}

void dialogcommande::on_pb_edit_clicked()
{ int id_commande=ui->lineEdit_idprod3->text().toInt();
         QSqlQuery query;
              query.prepare("SELECT * FROM COMMANDE WHERE id_commande= ? ");
              query.addBindValue(id_commande);

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
                     ui->four2_2->show();



                     }
                       else
                           QMessageBox::critical(nullptr, QObject::tr("EDIT"),
                                       QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);



}

void dialogcommande::on_pb_save_clicked()
{
    int id_commande = ui->lineEdit_idprod3->text().toInt();
    QString date_livraison= ui->lineEdit_stock_2->text();
    QString destination= ui->lineEdit_four1->text();
    int id_produit= ui->lineEdit_eval2->text().toInt();
    int id_client= ui->lineEdit_prix2 ->text().toInt();

  Commande e(id_commande,date_livraison, destination, id_produit, id_client);
  bool test=e.modifier(id_commande);
  if(test)
{ui->tabproduit->setModel(tmpcmd.afficher());

QMessageBox::information(nullptr, QObject::tr("Modifier une Commande"),
                  QObject::tr("Commande modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
     { QMessageBox::critical(nullptr, QObject::tr("Modifier une Commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel); }
  ui-> lineEdit_stock_2 ->hide();
  ui->lineEdit_four1  ->hide();
  ui-> lineEdit_eval2 ->hide();
  ui->four2 ->hide();
  ui->evall ->hide();
  ui->label_11->hide();
  ui->lineEdit_prix2->hide();

  ui->four2_2  ->hide();
  ui->lineEdit_idprod3->clear();

}

/*void dialogcommande::on_button_music_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/m2596/Desktop/AAAAAAAAAAA/song.mp3"));
    player->play();
    qDebug() << player ->errorString();
}
*/
void dialogcommande::on_tri1_clicked()
{
 ui->tabproduit->setModel(tmpcmd.affichertri1());
 ui->tri1->hide();
 ui->tri1_1->show();

}

void dialogcommande::on_tri1_1_clicked()
{

    ui->tabproduit->setModel(tmpcmd.affichertri1_1());
    ui->tri1_1->hide();
    ui->tri1->show();
}















/*void dialogcommande::on_pushButton_3_clicked()
{   int id_produit = ui->rech->text().toInt();

    bool test=tmpcmd.recherche(id_commande);
    if(test)
  {ui->tabproduit->setModel(tmpcmd.recherche(id_commande));//refresh


  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Recherche ID"),
                    QObject::tr("Erreur ID NOT FOUND !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }



*/

