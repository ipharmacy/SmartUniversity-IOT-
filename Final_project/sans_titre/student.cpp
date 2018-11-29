#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDebug>
#include"student.h"

student::student()
{
    id=0;
    login="";
    password="";
    name="";
    family="";
    nbpart=0;
    nbabs=0;
    subject1="";
    subject2="";
    subject3="";
    subject4="";


}
student::student(int id,QString login,QString password,QString name ,QString family,int nbpart,int nbabs,QString subject1,QString subject2,QString subject3,QString subject4,QDateTime schedule1,QDateTime schedule2,QDateTime schedule3,QDateTime schedule4)
{
    this->id=id;
    this->login=login;
    this->password=password;
    this->name=name;
    this->family=family;
    this->nbpart=nbpart;
    this->nbabs=nbabs;
    this->subject1=subject1;
    this->subject2=subject2;
    this->subject3=subject3;
    this->subject4=subject4;
    this->schedule1=schedule1;
    this->schedule2=schedule2;
    this->schedule3=schedule3;

    this->schedule4=schedule4;



}
int student::get_id()
{
    return id;
}
QString student::get_login()
{
    return login;
}
QString student::get_password()
{
    return password;
}
QString student::get_name()
{
    return name;
}
QString student::get_family()
{
    return family;
}
int student::get_nbpart()
{
    return nbpart;
}
int student::get_nbabs()
{
    return nbabs;
}

bool student::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(nbpart);
    QString res2=QString::number(nbabs);
    qDebug() <<"1";

    query.prepare("INSERT INTO student(id_student,login,pasword,name,family,nb_part,nb_abs,subject1,subject2,subject3,subject4,schedule1,schedule2,schedule3,schedule4)VALUES (:id, :login, :password, :name, :family, :nbpart, :nbabs, :subject1, :subject2, :subject3, :subject4, :schedule1, :schedule2, :schedule3, :schedule4)");



   query.bindValue(":id",res);
    query.bindValue(":nbpart",res1);
    query.bindValue(":nbabs",res2);
    query.bindValue(":login",login);
    query.bindValue(":password",password);
    query.bindValue(":name",name);


    query.bindValue(":family",family);
    query.bindValue(":subject1",subject1);
    query.bindValue(":subject2",subject2);
    query.bindValue(":subject3",subject3);
    query.bindValue(":subject4",subject4);
    query.bindValue(":schedule1",schedule1);
    query.bindValue(":schedule2",schedule2);


    query.bindValue(":schedule3",schedule3);
    query.bindValue(":schedule4",schedule4);





    return query.exec();
}
bool student::supprimer(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from student where id_student=:id ");
    query.bindValue(":id",res);
return query.exec();
}
bool student::modifier(int idd,QString log,QString pass,QString nom,QString pr,QString sub1,QString sub2,QString sub3,QString sub4,QDateTime sch1,QDateTime sch2,QDateTime sch3,QDateTime sch4)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("UPDATE student SET login= :log, pasword= :pass,name= :nom,family= :pr,subject1= :sub1,subject2= :sub2,subject3= :sub3,subject4= :sub4,schedule1= :sch1,schedule2= :sch2,schedule3= :sch3,schedule4= :sch4 where id_student=:idd");
    query.bindValue(":idd",res);
    query.bindValue(":log",log);
    query.bindValue(":pass",pass);
    query.bindValue(":nom",nom);
    query.bindValue(":pr",pr);
    query.bindValue(":sub1",sub1);
    query.bindValue(":sub2",sub2);
    query.bindValue(":sub3",sub3);
    query.bindValue(":sub4",sub4);
    query.bindValue(":sch1",sch1);
    query.bindValue(":sch2",sch2);
    query.bindValue(":sch3",sch3);
    query.bindValue(":sch4",sch4);


    return query.exec();



}
QSqlQueryModel *student::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from student");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("LOGIN"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("PASSWORD"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NAME"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("FAMILY"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Participation number"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Absence number"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("SUBJECT1"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("SUBJECT2"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("SUBJECT3"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("SUBJECT4"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("SCHEDULE1"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("SCHEDULE2"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("SCHEDULE3"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("SCHEDULE4"));
    return model;
}

