#ifndef PROFESOR_H
#define PROFESOR_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDateTime>
#include<QVector>

class profesor
{
public:
    profesor();
    profesor(int,QString,QString,QString,QString,QString,QDateTime,QDateTime);
    int get_id();
    QString get_login();
    QString get_password();
    QString get_name();
    QString get_family();
    QString get_subject();
    QString get_schedule();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,QDateTime,QDateTime);
     bool ajouter_part(int,int);
      bool supp_part(int,int);
     QSqlQueryModel *LD();
      QSqlQueryModel *LW();

private:
    int id;
    QString login,password,name,family,subject;
    QDateTime schedule1,schedule2;

};

#endif // PROFESOR_H
