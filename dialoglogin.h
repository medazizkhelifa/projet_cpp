#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialoglogin; }
QT_END_NAMESPACE

class Dialoglogin : public QDialog
{
    Q_OBJECT

public:
    Dialoglogin(QWidget *parent = nullptr);
    ~Dialoglogin();

private slots:
    void on_login_clicked();
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialoglogin *ui;
};
#endif // DIALOGLOGIN_H
