#ifndef DIALOGVEHICULE_H
#define DIALOGVEHICULE_H
#include "vehicule.h"
#include <QDialog>

namespace Ui {
class dialogvehicule;
}

class dialogvehicule : public QDialog
{
    Q_OBJECT

public:
    explicit dialogvehicule(QWidget *parent = nullptr);
    ~dialogvehicule();

private slots:
    void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_rech_textChanged(const QString &arg1);

    void on_pb_edit_clicked();

    void on_pb_save_clicked();

    void on_tri1_1_clicked();

    void on_tri1_clicked();

    void on_tri2_clicked();

    void on_tri2_1_clicked();

    void on_tri3_clicked();

    void on_tri3_1_clicked();

    void on_tri6_clicked();

    void on_tri6_1_clicked();

private:
    Ui::dialogvehicule *ui;
    vehicule tmpvehicule;

};

#endif // DIALOGVEHICULE_H
