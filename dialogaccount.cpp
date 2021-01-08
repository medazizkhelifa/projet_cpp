#include "dialogaccount.h"
#include "ui_dialogaccount.h"
#include <QMessageBox>
#include "account.h"

dialogaccount::dialogaccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogaccount)
{
    ui->setupUi(this);
}

dialogaccount::~dialogaccount()
{
    delete ui;
}
void dialogaccount::on_pushButton_clicked()
{
    QString username= ui->username->text();
    QString password= ui->password->text();
    QString nom= ui->name->text();
    QString prenom= ui->lastname->text();
    QString mail= ui->email->text();



    account e(username,password,nom,prenom,mail);
    bool test=e.ajouter();
    if(test)
  {
        //refresh
           // ui->comboBox->setModel(tmpmatch.afficher_list());
  QMessageBox::information(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("account ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter account"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    ui->name->clear();
    ui->username->clear();
    ui->lastname->clear();
    ui->email->clear();
    ui->password->clear();

    hide();

}
