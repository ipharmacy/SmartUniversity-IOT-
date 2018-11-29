#include "connexion.h"
#include <QDebug>




Connexion::Connexion()
{

}

void Connexion::createconnect()
{
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_proj2A");
db.setUserName("dhia2");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur
if (db.open())
    qDebug() <<"okbyvbyv";

}

