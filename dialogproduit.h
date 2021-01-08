#ifndef DIALOGPRODUIT_H
#define DIALOGPRODUIT_H

#include "produit.h"
#include <QMainWindow>
#include <QDialog>
#include <QMainWindow>
#include <QMediaPlayer>
namespace Ui {
class dialogproduit;
}

class dialogproduit : public QDialog
{
    Q_OBJECT

public:
    explicit dialogproduit(QWidget *parent = nullptr);
    ~dialogproduit();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

    void on_pb_save_clicked();

    void on_pb_edit_clicked();

    void on_button_music_clicked();

    void on_tri1_clicked();

    void on_tri1_1_clicked();

    void on_tri3_2_clicked();

    void on_tri2_clicked();

    void on_tri2_1_clicked();

    void on_tri3_clicked();

    void on_tri3_1_clicked();

    void on_tri4_clicked();

    void on_tri4_1_clicked();

    void on_tri5_clicked();

    void on_tri5_1_clicked();

    void on_tri6_clicked();

    void on_tri6_1_clicked();





    void on_pushButton_3_clicked();

    void on_rech_textChanged(const QString &arg1);

private:
    Ui::dialogproduit *ui;
    Produit tmpproduit;
        QMediaPlayer* player;
};


#endif // DIALOGPRODUIT_H
