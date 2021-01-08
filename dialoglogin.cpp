#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include "account.h"
#include "dialogaccount.h"
#include "dialogmenu.h"
#include "ui_dialogmenu.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QLabel>
#include <QPixmap>



Dialoglogin::Dialoglogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialoglogin)
{
    ui->setupUi(this);
}

Dialoglogin::~Dialoglogin()
{
    delete ui;
}


void Dialoglogin::on_login_clicked()
{
    QString username=ui->lineEdit->text();
       QString password= ui->lineEdit_2->text();
       QSqlQuery query;
           query.prepare("SELECT * FROM LOGIN WHERE USERNAME= ? AND PASSWORD= ?");
           query.addBindValue(username);
           query.addBindValue(password);
            query.exec();
              if(query.next())
              {
                   this->hide();
                  dialogmenu d;

                  d.exec();




                  }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("LOGIN"),
                                    QObject::tr("\nUser Name or Password is incorrect try again !\n"), QMessageBox::Cancel);

              ui->lineEdit->clear();
              ui->lineEdit_2->clear();
}
void Dialoglogin::on_commandLinkButton_clicked()
{
   dialogaccount d;

    d.exec();

}

void Dialoglogin::on_pushButton_clicked()
{
    this->close();
}
