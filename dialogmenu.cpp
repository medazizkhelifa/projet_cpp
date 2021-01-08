#include "dialogmenu.h"
#include "ui_dialogmenu.h"
#include "dialogstock.h"
#include "ui_dialogstock.h"
#include "dialogcommande.h"
#include "ui_dialogcommande.h"
#include "dialogproduit.h"
#include "ui_dialogproduit.h"
#include "dialogvehicule.h"
#include "ui_dialogvehicule.h"
dialogmenu::dialogmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogmenu)
{
    ui->setupUi(this);
}

dialogmenu::~dialogmenu()
{
    delete ui;
}

void dialogmenu::on_stock_clicked()
{
    this->close();
    dialogstock d;
    d.exec();
}




void dialogmenu::on_vehicule_clicked()
{
    this->close();
    dialogvehicule d;
    d.exec();
}

void dialogmenu::on_produit_clicked()
{
    this->close();
    dialogproduit d;
    d.exec();
}



void dialogmenu::on_close_clicked()
{
    this->close();
}





void dialogmenu::on_commande_clicked()
{
    this->close();
    dialogcommande d;
    d.exec();
}
