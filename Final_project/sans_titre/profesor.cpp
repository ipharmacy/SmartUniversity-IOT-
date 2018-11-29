#include "profesor.h"

#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include <QDateTime>
#include<QVector>
#include<QtAlgorithms>


profesor::profesor()
{
    id=0;
    login="";
    password="";
    name="";
    family="";
    subject="";

}
profesor::profesor(int id,QString login,QString password,QString name ,QString family,QString subject , QDateTime schedule1,QDateTime schedule2)
{
    this->id=id;
    this->login=login;
    this->password=password;
    this->name=name;
    this->family=family;
    this->subject=subject;
    this->schedule1=schedule1;
    this->schedule2=schedule2;
}
int profesor::get_id()
{
    return id;
}
QString profesor::get_login()
{
    return login;
}
QString profesor::get_password()
{
    return password;
}
QString profesor::get_name()
{
    return name;
}
QString profesor::get_family()
{
    return family;
}

QString profesor::get_subject()
{
    return subject;
}

bool profesor::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO profesor(id_prof,login_prof,password_prof,name_prof,family_prof,subject_prof,schedule1_prof,schedule2_prof)""VALUES (:id, :login, :password, :name, :family, :subject, :schedule1, :schedule2)");
    query.bindValue(":id",res);
    query.bindValue(":login",login);
    query.bindValue(":password",password);
    query.bindValue(":name",name);
    query.bindValue(":family",family);
    query.bindValue(":subject",subject);
    query.bindValue(":schedule1",schedule1);
    query.bindValue(":schedule2",schedule2);
    return query.exec();
}
bool profesor::supprimer(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from profesor where ID=:id ");
    query.bindValue(":id",res);
return query.exec();
}
bool profesor::modifier(int idd,QString log,QString pass,QString nom,QString pr,QString mat, QDateTime subj1, QDateTime subj2)
{
    QSqlQuery query;
    QString res=QString::number(idd);



    query.prepare("UPDATE profesor SET login_prof= :log, password_prof= :pass,name_prof= :nom,family_prof= :pr,subject_prof= :mat,schedule1_prof= :subj1,schedule2_prof= :subj2 where id_prof=:idd");
    query.bindValue(":idd",res);
    query.bindValue(":log",log);
    query.bindValue(":pass",pass);
    query.bindValue(":nom",nom);
    query.bindValue(":pr",pr);
    query.bindValue(":mat",mat);
    query.bindValue(":subj1",subj1);
    query.bindValue(":subj2",subj2);



    return query.exec();



}
QSqlQueryModel *profesor::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select id_prof,login_prof,name_prof,family_prof,subject_prof,schedule1_prof,schedule2_prof from profesor");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("LOGIN"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PASSWORD"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("FAMILY"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("SUBJECT"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("SCHEDULE1"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("SCHEDULE2"));
    return model;
}



bool profesor::ajouter_part(int idp,int ide)
    {

        QSqlQuery query,query1,query2,query3;

        QString res=QString::number(idp);
        QString res2=QString::number(ide);
        int test=0,test2=0;

       query.prepare("SELECT student.id_student,student.nb_part FROM student  INNER JOIN profesor ON student.subject1=profesor.subject_prof AND student.schedule1=profesor.schedule1_prof");

       query.exec();
        while (query.next()) {

        test=query.value(0).toInt();
        test2=query.value(1).toInt();




        }
        if(test==ide)
        {
            test2++;
            QString res3=QString::number(test2);

            query3.prepare("UPDATE student SET NB_PART=:test2  where ID_STUDENT=:ide");
            query3.bindValue("idp",res);
            query3.bindValue(":ide",res2);
            query3.bindValue(":test2",res3);


           return query3.exec();

        }else
        {
            return false;
        }
}

bool profesor::supp_part(int idp,int ide)
    {

        QSqlQuery query,query1,query2,query3;

        QString res=QString::number(idp);
        QString res2=QString::number(ide);
        int test=0,test2=0;

       query.prepare("SELECT student.id_student,student.nb_part FROM student  INNER JOIN profesor ON student.subject1=profesor.subject_prof AND student.schedule1=profesor.schedule1_prof");

       query.exec();
        while (query.next()) {

        test=query.value(0).toInt();
        test2=query.value(1).toInt();




        }
        if(test==ide)
        {
            test2--;
            QString res3=QString::number(test2);

            query3.prepare("UPDATE student SET NB_PART=:test2  where ID_STUDENT=:ide");
            query3.bindValue("idp",res);
            query3.bindValue(":ide",res2);
            query3.bindValue(":test2",res3);


           return query3.exec();

        }else
        {
            return false;
        }
}



QSqlQueryModel *profesor::LD()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;

    model->setQuery("select id_student,name,family,nb_part from student order by nb_part DESC");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("FAMILY"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("nbpart"));

    return model;
}
QSqlQueryModel *profesor::LW()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select id_student,name,family,nb_part from student order by nb_part ASC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("FAMILY"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("nbpart"));

    return model;
}
