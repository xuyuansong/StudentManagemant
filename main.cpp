#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.211.153");
    db.setDatabaseName("studentmanagemant");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"连接数据库成功";
    }else
    {
        qDebug()<<"连接数据库失败";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
