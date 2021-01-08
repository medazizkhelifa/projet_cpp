#include "dialogstock.h"
#include "ui_dialogstock.h"
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QComboBox>

dialogstock::dialogstock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogstock)
{
    ui->setupUi(this);
    ui->date->hide();
    ui->label_30->hide();
    ui->tridescid->hide();
    ui->tridesdate->hide();
    ui->tridescres->hide();
    ui->date2->hide();
    ui->modfierOk->hide();
    ui->reservationEdit->hide();
    timer = new QTimer (this);
                connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
                timer->start(1000);
}
void dialogstock::myfunction()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    QString time_text = dateTime.toString("dd.MM.yyyy hh:mm:ss");
    ui->date->setText(time_text);
    ui->date2->setText(time_text);


}


dialogstock::~dialogstock()
{
    delete ui;
}

void dialogstock::on_pushButton_clicked()
{
    this->hide();
    dialogmenu d;
    d.exec();
}

void dialogstock::on_ajouter_clicked()
{
 int id_stock = ui->stock->text().toInt();
 QString date_ajout =ui->date->text();
 QString date_reservation= ui->reservation->text();
 stock e(id_stock, date_ajout,date_reservation);
 bool test=e.ajouter();
 if(test)
 { ui->tabstock->setModel(tmpstock.afficher());
     ui->stock->clear();
     ui->reservation->clear();
     QMessageBox::information(nullptr, QObject::tr("Ajouter Stock"),
                           QObject::tr("Stock Ajouté ! ! .\n"
                                       "Click Close to exit."), QMessageBox::Close);


 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter un Stock"),
                 QObject::tr("Erreur ! Remplir les informations.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void dialogstock::on_pb_supprimer_3_clicked()
{
    int id_stock = ui->stocksup->text().toInt();
    bool test=tmpstock.supprimer(id_stock);
    if(test)
   {ui->tabstock->setModel(tmpstock.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un stock"),
                    QObject::tr("Stock supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un stock"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    }

void dialogstock::on_modifier_clicked()
{ int id_stock = ui->stockEdit ->text().toInt();
    QSqlQuery query;
            query.prepare("Select * from stock where id_stock= ? ");
    query.addBindValue(id_stock);
    query.exec();
    if(query.next()){
    ui->label_30->show();
    ui->modfierOk->show();
    ui->reservationEdit->show(); }
    else
        QMessageBox::critical(nullptr, QObject::tr("EDIT"),
         QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);

}

void dialogstock::on_modfierOk_clicked()
{
 int id_stock = ui->stockEdit->text().toInt();
 QString date_ajout =ui->date2->text();
 QString date_reservation= ui->reservationEdit->text();
 stock e(id_stock, date_ajout,date_reservation);

 bool test=e.modifier(id_stock);
 if(test)
 { ui->tabstock->setModel(tmpstock.afficher());
     ui->reservationEdit->clear();
     ui->stockEdit->clear();
     QMessageBox::information(nullptr, QObject::tr("Modifier Stock"),
                           QObject::tr("Stock Modifié ! ! .\n"
                                       "Click Close to exit."), QMessageBox::Close);


 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Modifier un Stock"),
                 QObject::tr("Erreur ! Remplir les informations.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}

void dialogstock::on_rech_3_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM stock WHERE id_stock LIKE'"+arg1+"%' or date_ajout LIKE'"+arg1+"%' or date_reservation LIKE'"+arg1+"%'");
     query->exec();
     model->setQuery(*query);
     ui->tabstock->setModel(model);
}

void dialogstock::on_tabWidget_tabBarClicked(int index)
{
ui->tabstock->setModel(tmpstock.afficher()); // print the tables
}

void dialogstock::on_triascid_clicked()
{  ui->triascid->hide();
   ui->tridescid->show();
   ui->tabstock->setModel(tmpstock.afficher1());
}

void dialogstock::on_triascres_clicked()
{   ui->triascres->hide();
    ui->tridescres->show();
    ui->tabstock->setModel(tmpstock.afficher3());
}

void dialogstock::on_triascdate_clicked()
{   ui->triascdate->hide();
    ui->tridesdate->show();
    ui->tabstock->setModel(tmpstock.afficher2());
}

void dialogstock::on_tridescid_clicked()
{
     ui->tridescid->hide();
     ui->triascid->show();
     ui->tabstock->setModel(tmpstock.afficher11());
}

void dialogstock::on_tridescres_clicked()
{    ui->tridescres->hide();
     ui->triascres->show();
      ui->tabstock->setModel(tmpstock.afficher33());

}

void dialogstock::on_tridesdate_clicked()
{
    ui->tridesdate->hide();
    ui->triascdate->show();
    ui->tabstock->setModel(tmpstock.afficher22());
}
