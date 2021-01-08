#ifndef DIALOGCOMMANDE_H
#define DIALOGCOMMANDE_H

#include <QDialog>
#include "dialogmenu.h"
#include <QDialog>
#include <QMediaPlayer>
#include "commande.h"
namespace Ui {
class dialogcommande;
}

class dialogcommande : public QDialog
{
    Q_OBJECT

public:
    explicit dialogcommande(QWidget *parent = nullptr);
    ~dialogcommande();

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
    void on_pushButton_3_clicked();

private:
    Ui::dialogcommande *ui;
    Commande tmpcmd;

};



#endif // DIALOGCOMMANDE_H
