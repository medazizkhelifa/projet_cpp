#ifndef DIALOGMENU_H
#define DIALOGMENU_H

#include <QDialog>

namespace Ui {
class dialogmenu;
}

class dialogmenu : public QDialog
{
    Q_OBJECT

public:
    explicit dialogmenu(QWidget *parent = nullptr);
    ~dialogmenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_stock_clicked();

    void on_cammande_clicked();

    void on_vehicule_clicked();

    void on_produit_clicked();

    void on_close_clicked();

    void on_commande_clicked();

private:
    Ui::dialogmenu *ui;
};

#endif // DIALOGMENU_H
