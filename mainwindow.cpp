#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "softwareKeyd.h"
#include <qDebug>
#include <QDateTime>

#include<QByteArray>

#include "decode.h"



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

void MainWindow::on_pushButton_clicked()
{
    QDateTime current_time =QDateTime::currentDateTime();
    char MD5key[64] = { 0 };
    int flag = GetSoftwareKey(MD5key);
    QString keystring = QString(QLatin1String(MD5key));
    qDebug().noquote()<<"MD5key:"<<MD5key;
    qDebug().noquote()<<"MD5key:"<<keystring;

    QString time=ui->lineEdit->text();
    qDebug().noquote()<<"time:"<<time;
    QString source=MD5key+time;//current_time.toString("yyyyMMdd");
    qDebug().noquote()<<"source:"<<source<<source.size();

    uchar *source_tochar;
    uchar result[100]={0};
    char  key[]="816901";
    QByteArray ba=source.toLatin1();//先把QString转换成array，再转换成uhcar
    source_tochar= (unsigned char *)ba.data();

    get_DES_ecb3_encrypt(source_tochar,40,key,1,result);

    QByteArray res_array;
    for(int i=0;i<48;i++)res_array.append(result[i]);//把求得的uchar类型存到array里面，方便qt对其操作

    qDebug()<<"res_array:"<<res_array<<res_array.size();

    ui->textEdit->clear();
    ui->textEdit->append(res_array.toBase64());

    QString re_key,re_date;
    decode(res_array.toBase64(),&re_key,&re_date);

    qDebug()<<re_key<<re_date;
//    ui->textEdit->clear();
//    //ui->textEdit->append(QString::fromUtf8(reinterpret_cast<char *>(decode_source), 40));
//    ui->textEdit->append(res_array.toBase64());
}

void MainWindow::on_decode_clicked()
{
    QString other_sered_temp=ui->other_sered->toPlainText();

    QByteArray other_sered=other_sered_temp.toLatin1();
    QString re_key,re_date;
    decode(other_sered,&re_key,&re_date);

    ui->other_id->clear();
    ui->other_id->append(re_key);
    ui->other_date->clear();
    ui->other_date->append(re_date);
}

void MainWindow::on_encode_clicked()
{
    QString other_date=ui->other_date->toPlainText();
    QString other_id=ui->other_id->toPlainText();

    QString source=other_id+other_date;
    qDebug().noquote()<<"source:"<<source<<source.size();

    uchar *source_tochar;
    uchar result[100]={0};
    char  key[]="816901";
    QByteArray ba=source.toLatin1();//先把QString转换成array，再转换成uhcar
    source_tochar= (unsigned char *)ba.data();

    get_DES_ecb3_encrypt(source_tochar,40,key,1,result);

    QByteArray res_array;
    for(int i=0;i<48;i++)res_array.append(result[i]);//把求得的uchar类型存到array里面，方便qt对其操作

    ui->other_key->clear();
    ui->other_key->append(res_array.toBase64());
}
