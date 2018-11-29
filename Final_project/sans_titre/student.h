#ifndef STUDENT_H
#define STUDENT_H


#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDateTime>



class student
{
public:
    student();
    student(int,QString,QString,QString,QString,int,int,QString,QString,QString,QString,QDateTime,QDateTime,QDateTime,QDateTime);
    int get_id();
    QString get_login();
    QString get_password();
    QString get_name();
    QString get_family();
    int get_nbabs();
    int get_nbpart();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString,QString,QString,QString,QString,QDateTime,QDateTime,QDateTime,QDateTime);
private:
    int id,nbabs,nbpart;
   QString login,password,name,family,subject1,subject2,subject3,subject4;
   QDateTime schedule1,schedule2,schedule3,schedule4;
};

#endif // STUDENT_H
