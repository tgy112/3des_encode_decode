#include "mainwindow.h"
#include <QApplication>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowIcon(QIcon(":\bg.ico"));

    w.show();

//qDebug()<<(4&(0x01<<2));
    return a.exec();
}
