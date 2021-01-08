#ifndef DIALOGSTOCK_H
#define DIALOGSTOCK_H
#include "stock.h"
#include "dialogmenu.h"
#include <QDialog>
#include <QDialog>
#include <QTimer>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
namespace Ui {
class dialogstock;
}

class dialogstock : public QDialog
{
    Q_OBJECT

public:
    explicit dialogstock(QWidget *parent = nullptr);
    ~dialogstock();
public slots:
    void myfunction();
private slots:
    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_pb_supprimer_3_clicked();

    void on_modifier_clicked();

    void on_modfierOk_clicked();

    void on_rech_3_textChanged(const QString &arg1);

    void on_tabWidget_tabBarClicked(int index);

    void on_triascid_clicked();

    void on_triascres_clicked();

    void on_triascdate_clicked();

    void on_tridescid_clicked();

    void on_tridescres_clicked();

    void on_tridesdate_clicked();

private:
    Ui::dialogstock *ui;
    stock tmpstock;
    QTimer *timer;
};

#endif // DIALOGSTOCK_H
