#include<iostream>
#include "mainwindow.h"
#include <QDialog>
#include <QFileDialog>
#include <QDebug>
#include<QLayout>
#include <string>
#include<conbimetxt.h>
#include "ui_mainwindow.h"
using namespace std;

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


void MainWindow::on_choose_clicked()
{
    file_path = QFileDialog::getExistingDirectory(this,"choose list","./");
      if(file_path.isEmpty())
     {
         return;
     }else{
        qDebug() << file_path << endl;
        cout<<file_path.toStdString()<<endl;
        ui->fileroad->setText(file_path);
    }
}


void MainWindow::on_fileroad_textEdited(const QString &filer)
{

    cout<<filer.toStdString()<<endl;
}


void string_replace(string&s1,const string&s2,const string&s3)
{
    string::size_type pos=0;
    string::size_type a=s2.size();
    string::size_type b=s3.size();
    while((pos=s1.find(s2,pos))!=string::npos)
    {
        s1.replace(pos,a,s3);
        pos+=b;
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString fr=ui->fileroad->text();
    string frr=fr.toStdString();
    if(frr.length()==0)
    {

    }
    else
    {
    cout<<"length:"<<frr.length()<<frr<<endl;
    string_replace(frr,"/","\\");

    //string yuan="/";
    //frr=frr.replace(frr.find(yuan),yuan.length(),"\\");
    cout<<"fileroad:"<<frr<<endl;
    ConbimeTxt cbt;
    cbt.comBine(frr);
    //QDialog *dialog =new QDialog;
   // dialog->show();
    dlg = new QDialog(this);
    QVBoxLayout *layout =new QVBoxLayout;
    QLabel *label = new QLabel(dlg);
    QPushButton * btn = new QPushButton("ok");
    label->setText("Combine success!");
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clickedclose()));
    layout->addWidget(label);
    layout->addWidget(btn);
    dlg->setLayout(layout);
    dlg->resize(150,50);
    dlg->setModal(true);
    dlg->show();
    }

}
void MainWindow::on_pushButton_clickedclose()
{
    dlg->close();
}
