#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>


class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // DATABASE_H
