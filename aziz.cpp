#include "aziz.h"
#include "ui_aziz.h"
#include "vehicule.h"
#include "stock.h"
#include "QMessageBox"
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QPrinter>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
QT_CHARTS_USE_NAMESPACE
#include <QTextStream>

aziz::aziz(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::aziz)
{

    ui->setupUi(this);

    ui->data->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->data_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->DATE->setDate(QDate::currentDate());
    vehicule tmp;
    employee tmp2;
    ui->data->setModel(tmp.afficher());
    ui->id_employee->setModel(tmp2.getIDs());
    ui->id_stock->setModel(tmp2.getIDs());
    ui->data_2->setModel(tmp2.afficher());
    ui->id_vehicule->setModel(tmp.getIDs());
}

aziz::~aziz()
{
    delete ui;
}


void aziz::on_pb_ajouter_clicked()
{
    vehicule tmp(ui->id_vehicule2->text().toInt(),ui->destination->text(),ui->id_employee->currentText().toInt(),ui->id_stock->currentText().toInt(),ui->DATE->date());
    if(tmp.ajouter())
    {
        ui->data->setModel(tmp.afficher());
        ui->lineEdit_id_6->setText("");
        ui->id_vehicule->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void aziz::on_pb_supprimer_3_clicked()
{
    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un VEHICULE du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        vehicule tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->destination->text(),ui->id_employee->currentText().toInt(),ui->id_stock->currentText().toInt(),ui->DATE->date());
        if(tmp.modifier())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->id_vehicule->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}

void aziz::on_pb_supprimer_4_clicked()
{

    if(ui->data->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un VEHICULE du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        vehicule tmp(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toInt(),ui->destination->text(),ui->id_employee->currentText().toInt(),ui->id_stock->currentText().toInt(),ui->DATE->date());
        if(tmp.supprimer())
        {
            ui->data->setModel(tmp.afficher());
            ui->lineEdit_id_6->setText("");
            ui->id_vehicule->setModel(tmp.getIDs());
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}

void aziz::on_data_clicked(const QModelIndex &index)
{
    ui->id_vehicule2->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),0)).toString());
    ui->destination->setText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),1)).toString());
    ui->id_employee->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),2)).toString());
    ui->id_stock->setCurrentText(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),3)).toString());

    ui->DATE->setDate(ui->data->model()->data(ui->data->model()->index(ui->data->currentIndex().row(),4)).toDate());

}

void aziz::on_lineEdit_id_6_textChanged(const QString &arg1)
{

     vehicule tmp;
     if(ui->lineEdit_id_6->text()!="")
     {

     //ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
         QString b=ui->comboBox->currentText();
         QString a=ui->lineEdit_id_6->text();
         ui->data->setModel(tmp.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
     }else
     ui->data->setModel(tmp.afficher());
}

void aziz::on_comboBox_currentTextChanged(const QString &arg1)
{
    vehicule tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
    else
    ui->data->setModel(tmp.afficher());
}



void aziz::on_pb_ajouter_2_clicked()
{
    employee tmp(ui->id_employee->text().toInt(),ui->id_stocks->text(),ui->date_ajout->text(),ui->id_vehicule->currentText().toInt(),ui->date_de_livraision->text());
    if(tmp.ajouter())
    {
        ui->data_2->setModel(tmp.afficher());
        ui->lineEdit_id_7->setText("");
        ui->id_employee->setModel(tmp.getIDs());
        ui->id_stock->setModel(tmp.getIDs());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Success.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
                          QObject::tr("Erreur.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void aziz::on_pb_supprimer_5_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un Don du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        employee tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->id_stocks->text(),ui->date_ajout->text(),ui->id_vehicule->currentText().toInt(),ui->date_de_livraision->text());
        if(tmp.modifier())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->id_employee->setModel(tmp.getIDs());
            ui->id_stock->setModel(tmp.getIDs());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void aziz::on_pb_supprimer_6_clicked()
{
    if(ui->data_2->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un Donateur du Tableau.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
        employee tmp(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toInt(),ui->id_stocks->text(),ui->date_ajout->text(),ui->id_vehicule->currentText().toInt(),ui->date_de_livraision->text());
        if(tmp.supprimer())
        {
            ui->data_2->setModel(tmp.afficher());
            ui->lineEdit_id_7->setText("");
            ui->id_employee->setModel(tmp.getIDs());
            ui->id_stock->setModel(tmp.getIDs());

            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void aziz::on_lineEdit_id_7_textChanged(const QString &arg1)
{
    employee tmp;
    if(ui->lineEdit_id_7->text()!="")
    {
   // ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
        QString b=ui->comboBox_2->currentText();
        QString a=ui->lineEdit_id_7->text();
        ui->data_2->setModel(tmp.displayClause("WHERE ("+b+" LIKE '%"+a+"%')"));
    }else
    ui->data_2->setModel(tmp.afficher());
}




void aziz::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    employee tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
    else
    ui->data_2->setModel(tmp.afficher());
}

void aziz::on_data_2_clicked(const QModelIndex &index)
{
    ui->id_employee->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),0)).toString());
    ui->id_stocks->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),1)).toString());
    ui->date_ajout->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),2)).toString());
    ui->id_vehicule->setCurrentText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),3)).toString());
    ui->date_de_livraision->setText(ui->data_2->model()->data(ui->data_2->model()->index(ui->data_2->currentIndex().row(),4)).toString());
}


void aziz::on_id_tri_currentTextChanged(const QString &arg1)
{
    vehicule tmp;
    if(ui->lineEdit_id_6->text()!="")
    ui->data->setModel(tmp.displayClause("WHERE "+ui->comboBox->currentText()+"="+ui->lineEdit_id_6->text()+" ORDER BY "+ui->id_tri->currentText()));
    else
    ui->data->setModel(tmp.displayClause("ORDER BY "+ui->id_tri->currentText()));
}

void aziz::on_id_tri2_currentTextChanged(const QString &arg1)
{
    employee tmp;
    if(ui->lineEdit_id_7->text()!="")
    ui->data_2->setModel(tmp.displayClause("WHERE "+ui->comboBox_2->currentText()+"='"+ui->lineEdit_id_7->text()+"' ORDER BY "+ui->id_tri2->currentText()));
    else
    ui->data_2->setModel(tmp.displayClause("ORDER BY "+ui->id_tri2->currentText()));
}

void aziz::on_pushButton_2_clicked()
{
    {
         //QDateTime datecreation = date.currentDateTime();
        //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                       QPdfWriter pdf("C:/Users/aziz/Desktop/vehicule.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::green);
                           painter.setFont(QFont("Arial", 25));
                           painter.drawText(1500,1400,"Les vehicules");
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Arial", 10));
                          // painter.drawText(1100,2000,afficheDC);
                           painter.drawRect(100,100,7300,2600);
                           //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/aziz/Desktop/img.jpg"));
                           painter.drawRect(0,3000,9600,500);
                           painter.setFont(QFont("Arial", 8));
                           painter.drawText(300,3300,"ID vehicule");
                           painter.drawText(2300,3300,"DESTINATION");
                           painter.drawText(4300,3300,"ID EMLPOYEE");
                           painter.drawText(6300,3300,"ID STOCK");
                           painter.drawText(8300,3300,"DATE");
                           QSqlQuery query;
                           query.prepare("select * from vehicule");
                           query.exec();
                           while (query.next())
                           {
                               painter.drawText(300,i,query.value(0).toString());
                               painter.drawText(2300,i,query.value(1).toString());
                               painter.drawText(4500,i,query.value(2).toString());
                               painter.drawText(6500,i,query.value(3).toString());
                               painter.drawText(8000,i,query.value(4).toString());
                              i = i + 500;
                           }
                           int reponse = QMessageBox::question(this, "Génerer PDF", "Voulez Vous Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                               if (reponse == QMessageBox::Yes)
                               {

                                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/aziz/Desktop/vehicule.pdf"));

                                   painter.end();
                               }
                               if (reponse == QMessageBox::No)
                               {
                                    painter.end();
                               }
        }

}


void aziz::on_pushButton22_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from EMLPOYEE where DATE_AJOUT < 5 ");
                float salaire=model->rowCount();
                model->setQuery("select * from EMLPOYEE where DATE_AJOUT  between 5 and 10 ");
                float salairee=model->rowCount();
                model->setQuery("select * from EMLPOYEE where DATE_AJOUT>10 ");
                float salaireee=model->rowCount();
                float total=salaire+salairee+salaireee;
                QString a=QString("moins de 5 employees "+QString::number((salaire*100)/total,'f',2)+"%" );
                QString b=QString("entre 5 et 10 employees "+QString::number((salairee*100)/total,'f',2)+"%" );
                QString c=QString("+10 employees "+QString::number((salaireee*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,salaire);
                series->append(b,salairee);
                series->append(c,salaireee);
        if (salaire!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( salairee!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
        if(salaireee!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
        }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("Pourcentage Par Salaire:totale de "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();

    }

