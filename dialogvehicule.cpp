#include "dialogvehicule.h"
#include "ui_dialogvehicule.h"
#include "dialogmenu.h"
#include "vehicule.h"
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include <QComboBox>
dialogvehicule::dialogvehicule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogvehicule)
{
    ui->setupUi(this);
    ui->nouv_destin->hide();
    ui->nouvid_emp->hide();
    ui->nouvid_stock->hide();
    ui->four2_2->hide();
    ui->four2->hide();
    ui->evall->hide();
    ui->pb_save->hide();

}

dialogvehicule::~dialogvehicule()
{
    delete ui;
}

void dialogvehicule::on_pushButton_clicked()
{   this->hide();
    dialogmenu d;
    d.exec();
}

void dialogvehicule::on_pb_ajouter_clicked()
{
    int id_vehicule = ui->id_vehicule->text().toInt();
    QString destination = ui->destination->text();
    int id_employer = ui->id_employer->text().toInt();
    int id_stock = ui->id_stock->text().toInt();
    vehicule e(id_vehicule,destination,id_employer,id_stock);
    bool test=e.ajouter();
    if(test)
    {
        ui->tabvehicule->setModel(tmpvehicule.afficher());
        ui->id_vehicule->clear();
        ui->destination->clear();
        ui->id_employer->clear();
        ui->id_stock->clear();
        QMessageBox::information(nullptr, QObject::tr("Ajouter Vehicule"),
                              QObject::tr("Vehicule Ajouté ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Vehicule"),
                    QObject::tr("Erreur ! Remplir les informations.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void dialogvehicule::on_pb_supprimer_clicked()
{
    int id_vehicule = ui->vehicule_sup->text().toInt();
    bool test=tmpvehicule.supprimer(id_vehicule);
    if(test)
    {ui->tabvehicule->setModel(tmpvehicule.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Vehicule"),
                    QObject::tr("Vehicule supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer  une Vehicule"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogvehicule::on_tabWidget_tabBarClicked(int index)
{
    ui->tabvehicule->setModel(tmpvehicule.afficher());
}

void dialogvehicule::on_rech_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * FROM vehicule WHERE id_vehicule LIKE'"+arg1+"%' or destination LIKE'"+arg1+"%' or id_employer LIKE'"+arg1+"%' or id_stock LIKE '"+arg1+"%'");
     query->exec();
     model->setQuery(*query);
     ui->tabvehicule->setModel(model);
}

void dialogvehicule::on_pb_edit_clicked()
{
 int id_vehicule = ui->idveh_mod->text().toInt();
 QSqlQuery query;
 query.prepare("Select * from vehicule where id_vehicule= ? ");
query.addBindValue(id_vehicule);
query.exec();
if(query.next()){

ui->nouv_destin->show();
ui->nouvid_emp->show();
ui->nouvid_stock->show();
ui->four2_2->show();
ui->four2->show();
ui->evall->show();
ui->pb_save->show();
    }
else
    QMessageBox::critical(nullptr, QObject::tr("EDIT"),
     QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);
}

void dialogvehicule::on_pb_save_clicked()
{
    int id_vehicule = ui->idveh_mod->text().toInt();
    QString destination = ui->nouv_destin->text();
    int id_employer = ui->nouvid_emp->text().toInt();
    int id_stock = ui->nouvid_stock->text().toInt();
    vehicule e(id_vehicule,destination,id_employer,id_stock);
    bool test=e.modifier(id_vehicule);
    if(test)
    { ui->tabvehicule->setModel(tmpvehicule.afficher());
        ui->idveh_mod->clear();
        ui->nouv_destin->clear();
        ui->nouvid_emp->clear();
        ui->nouvid_stock->clear();
        ui->nouv_destin->hide();
        ui->nouvid_emp->hide();
        ui->nouvid_stock->hide();
        ui->four2_2->hide();
        ui->four2->hide();
        ui->evall->hide();
         ui->pb_save->hide();
        QMessageBox::information(nullptr, QObject::tr("Modifier Vehicule"),
                              QObject::tr("Vehicule Modifié ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Vehicule"),
                    QObject::tr("Erreur ! Remplir les informations.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void dialogvehicule::on_tri1_1_clicked()
{
   ui->tri1_1->hide();
   ui->tri1->show();
   ui->tabvehicule->setModel(tmpvehicule.afficher1());

}

void dialogvehicule::on_tri1_clicked()
{
    ui->tri1->hide();
    ui->tri1_1->show();
    ui->tabvehicule->setModel(tmpvehicule.afficher11());
}

void dialogvehicule::on_tri2_clicked()
{
    ui->tri2->hide();
    ui->tri2_1->show();
      ui->tabvehicule->setModel(tmpvehicule.afficher2());
}

void dialogvehicule::on_tri2_1_clicked()
{
    ui->tri2_1->hide();
    ui->tri2->show();
       ui->tabvehicule->setModel(tmpvehicule.afficher22());
}

void dialogvehicule::on_tri3_clicked()
{
    ui->tri3->hide();
    ui->tri3_1->show();
       ui->tabvehicule->setModel(tmpvehicule.afficher3());
}

void dialogvehicule::on_tri3_1_clicked()
{
    ui->tri3_1->hide();
    ui->tri3->show();
       ui->tabvehicule->setModel(tmpvehicule.afficher33());
}

void dialogvehicule::on_tri6_clicked()
{
    ui->tri6->hide();
    ui->tri6_1->show();
       ui->tabvehicule->setModel(tmpvehicule.afficher4());
}

void dialogvehicule::on_tri6_1_clicked()
{
    ui->tri6_1->hide();
    ui->tri6->show();
           ui->tabvehicule->setModel(tmpvehicule.afficher44());
}
