#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "profesor.h"
#include "connexion.h"
#include"student.h"
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_profmanag_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//page_1
}

void MainWindow::on_addprof_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);//add user
}

void MainWindow::on_deleteprof_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);//delete_user
}

/*void MainWindow::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

*/

void MainWindow::on_add_submit_clicked()
{
    QString ch;

    if(ui->add_id->text()=="" || ui->add_name->text()=="" || ui->add_family->text()=="" || ui->add_password->text()=="" || ui->add_login->text()==""  || ui->add_subject->text()== "" )
    {
        QMessageBox::information(this,tr("fail"),tr("Please check your information "));
    }
    else
    {

    int id=ui->add_id->text().toInt();
    QString name=ui->add_name->text();
    QString login=ui->add_login->text();
    QString password=ui->add_password->text();
    QString family=ui->add_family->text();
    QString subject=ui->add_subject->text();
    QDateTime schedule1=ui->dateTimeEdit_9->dateTime();
    QDateTime schedule2=ui->dateTimeEdit_10->dateTime();
    profesor p(id,login,password,name,family,subject,schedule1,schedule2);
    bool test=p.ajouter();
    if (test)
    {
        QMessageBox::information(this,tr("succes"),tr("Ajouter avec succés"));
    }

    }
}

void MainWindow::on_add_cancel_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);//page_1
}

void MainWindow::on_delete_submit_clicked()
{
    int id = ui->del_id->text().toInt();
    if(ui->del_id->text()=="" )
    {
        QMessageBox::information(this,tr("fail"),tr("Please check your information "));
    }
    else
    {


    bool test=tmpprof.supprimer(id);
    if(test)
    {

        QMessageBox::information(this,tr("succes"),tr("supprimer avec succés"));

    }else
    {
        QMessageBox::information(this,tr("fail"),tr("echec de suppresion"));

    }
}
}

void MainWindow::on_delete_cancel_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//page_1

}

void MainWindow::on_dell_add_clicked()
{
       ui->stackedWidget->setCurrentIndex(3);//add user
}

void MainWindow::on_deleteprof_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);//delete_user
}

void MainWindow::on_add_mod_clicked()
{
   ui->stackedWidget->setCurrentIndex(9);//modify
}

void MainWindow::on_mod_del_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);//delete_user
}

void MainWindow::on_mod_add_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);//add_prof
}

void MainWindow::on_modifyprof_clicked()
{
   ui->stackedWidget->setCurrentIndex(9);//modify_prof
}

void MainWindow::on_del_modify_clicked()
{
   ui->stackedWidget->setCurrentIndex(9);//modify
}

void MainWindow::on_mod_cancel_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);//page_1
}

void MainWindow::on_mod_submit_clicked()
{
   int id = ui->mod_id->text().toInt();
   QString name=ui->mod_name->text();
   QString login=ui->mod_log->text();
   QString password=ui->mod_password->text();
   QString family=ui->mod_family->text();
   QString subject=ui->mod_subject->text();
   QDateTime schedule1=ui->dateTimeEdit_11->dateTime();
   QDateTime schedule2=ui->dateTimeEdit_12->dateTime();
   if(ui->mod_id->text()=="" || ui->mod_name->text()=="" || ui->mod_family->text()=="" || ui->mod_password->text()=="" || ui->mod_log->text()==""  || ui->mod_subject->text()== "" )
   {
       QMessageBox::information(this,tr("fail"),tr("Please check your information "));
   }
   else
   {


   profesor p;
   bool test=p.modifier(id,login,password,name,family,subject,schedule1,schedule2);

       if(test)
       {

           QMessageBox::information(this,tr("succes"),tr("Modifier avec succés"));

       }else
       {
           QMessageBox::information(this,tr("fail"),tr("echec de modification"));

       }

}
}

void MainWindow::on_student_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);//page_1_student

}

void MainWindow::on_proff_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);//page_prof
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);//page_profmanag

}

void MainWindow::on_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    QString ch;

    if(ui->stud_id->text()=="" || ui->stud_name->text()=="" || ui->stud_family->text()=="" || ui->stud_pass->text()=="" || ui->stud_login->text()=="")
    {
        QMessageBox::information(this,tr("fail"),tr("Please check your information "));
    }
    else
    {

    int id=ui->stud_id->text().toInt();
    QString name=ui->stud_name->text();
    QString login=ui->stud_login->text();
    QString password=ui->stud_pass->text();
    QString family=ui->stud_family->text();

    QString subject1=ui->stud_add_subj1->text();
    QString subject2=ui->stud_add_subj2->text();
    QString subject3=ui->stud_add_subj3->text();
    QString subject4=ui->stud_add_subj4->text();


 QDateTime schedule1 = ui->dateTimeEdit->dateTime();
 QDateTime schedule2 = ui->dateTimeEdit_2->dateTime();
 QDateTime schedule3 = ui->dateTimeEdit_3->dateTime();
 QDateTime schedule4 = ui->dateTimeEdit_4->dateTime();
   // schedule1 = date1_y+ date1_m+date1_d;
    qDebug() << schedule1;


    qDebug() <<"65";
    student s(id,login,password,name,family,0,0,subject1,subject2,subject3,subject4,schedule1,schedule2,schedule3,schedule4);
    bool test;
    qDebug() <<"55";

            test =s.ajouter();
    qDebug() <<"10";

    if (test)
    {
        QMessageBox::information(this,tr("succes"),tr("Ajouter avec succés"));
    }

    }
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);//page_1
}

void MainWindow::on_pushButton_10_clicked()
{
    int id = ui->stud_del->text().toInt();
    if(ui->stud_id->text()=="")
    {
        QMessageBox::information(this,tr("fail"),tr("Please check your information "));
    }
    else
    {


    bool test=tmpstud.supprimer(id);
    if(test)
    {

        QMessageBox::information(this,tr("succes"),tr("supprimer avec succés"));

    }else
    {
        QMessageBox::information(this,tr("fail"),tr("echec de suppresion"));

    }
}
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);//page_1
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);//page_1

}

void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
      ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_17_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_15_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_23_clicked()
{
    int id = ui->mod_stud_id->text().toInt();
    QString name=ui->mod_stud_name->text();
    QString login=ui->mod_stud_log->text();
    QString password=ui->mod_stud_pass->text();
    QString family=ui->mod_stud_family->text();


    QString subject1=ui->stud_mod_subj1->text();
    QString subject2=ui->stud_mod_subj1_2->text();
    QString subject3=ui->stud_mod_subj1_3->text();
    QString subject4=ui->stud_mod_subj1_4->text();


    QDateTime schedule1 = ui->dateTimeEdit_5->dateTime();
    QDateTime schedule2 = ui->dateTimeEdit_6->dateTime();
    QDateTime schedule3 = ui->dateTimeEdit_7->dateTime();
    QDateTime schedule4 = ui->dateTimeEdit_8->dateTime();
      // schedule1 = date1_y+ date1_m+date1_d;
       qDebug() << schedule1;

       if(ui->mod_stud_id->text()=="" || ui->mod_stud_log->text()=="" || ui->mod_stud_family->text()=="" || ui->mod_stud_name->text()=="" || ui->mod_stud_pass->text()=="")
       {
           QMessageBox::information(this,tr("fail"),tr("Please check your information "));
       }else
       {




    student s;
    bool test=s.modifier(id,login,password,name,family,subject1,subject2,subject3,subject4,schedule1,schedule2,schedule3,schedule4);

        if(test)
        {

            QMessageBox::information(this,tr("succes"),tr("Modifier avec succés"));

        }else
        {
            QMessageBox::information(this,tr("fail"),tr("echec de modification"));

        }
}
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}

void MainWindow::on_pushButton_4_clicked()
{
  ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_26_clicked()
{
      ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pushButton_27_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_28_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_34_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}

void MainWindow::on_pushButton_31_clicked()
{
    ui->tableView->setModel(tmpprof.afficher());
}

void MainWindow::on_prof_cancel_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_36_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_37_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_38_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_39_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_35_clicked()
{
    ui->tableView_2->setModel(tmpstud.afficher());
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_40_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_pushButton_41_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);

}

void MainWindow::on_pushButton_46_clicked()
{
   int idp = ui->lineEdit->text().toInt();
   int ide = ui->lineEdit_2->text().toInt();
   profesor p;
   bool test=p.ajouter_part(idp,ide);

       if(test)
       {

           QMessageBox::information(this,tr("succes"),tr("Note ajouter avec succés"));

       }else
       {
           QMessageBox::information(this,tr("fail"),tr("echec"));

       }


   // ui->tableView_3->setModel(p.ajouter_part(idp,ide));
}

void MainWindow::on_pushButton_42_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_pushButton_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_55_clicked()
{
    ui->tableView_3->setModel(tmpprof.LD());
}

void MainWindow::on_pushButton_56_clicked()
{
    ui->tableView_3->setModel(tmpprof.LW());
}

void MainWindow::on_pushButton_49_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_58_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_54_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_51_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_59_clicked()
{
 ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_60_clicked()
{
 ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_47_clicked()
{
    int idp = ui->lineEdit->text().toInt();
    int ide = ui->lineEdit_2->text().toInt();
    profesor p;
    bool test=p.supp_part(idp,ide);

        if(test)
        {

            QMessageBox::information(this,tr("succes"),tr("Note supprimer avec succés"));

        }else
        {
            QMessageBox::information(this,tr("fail"),tr("echec"));

        }

}

void MainWindow::on_pushButton_53_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}
