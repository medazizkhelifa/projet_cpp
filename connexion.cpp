#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("slim");//inserer le nom de la source de données ODBC
db.setUserName("slim");//inserer nom de l'utilisateur
db.setPassword("slim");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
