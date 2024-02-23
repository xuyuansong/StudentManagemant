#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "homewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.211.153");
    db.setDatabaseName("studnetmangemant");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"连接数据库成功";
    }else
    {
        qDebug()<<"连接数据库失败";
    }

    ui->LoginBtn->setText("登录");
    ui->downBtn->setText("关闭");
    ui->registerBtn->setText("注册");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginBtn_clicked()
{
    QString username=ui->user->text();
    QString password=ui->password->text();
    QString ident;
    if(ui->studentRadio->isChecked())
    {
        ident="student";
    }else if(ui->adminRadio->isChecked())
    {
        ident="admin";
    }else
    {
        QMessageBox::warning(nullptr,"警告","请选择用户类型");
        return;
    }
    //qDebug()<<"输入的用户名:"<<username<<" "<<"密码:"<<password;
    QSqlQuery query;
    QString selectSql="select * from " + ident + " where username='" + username+ "'";
    query.exec(selectSql);
    if(query.next())
    {
        //查询结果非空,取出用户密码判断是否匹配
        if(query.value("password").toString()==password)
        {
            //密码正确，进入应用
            enterApp(username);
        }else
        {
            ui->password->setText("");
            QMessageBox::warning(nullptr,"错误","密码错误");
        }
    }else
    {
        //查询结果为空，用户不存在
        QMessageBox::warning(nullptr,"警告","用户不存在");
    }
}

void MainWindow::enterApp(QString username)
{
    this->close();
    homeWindow* home = new homeWindow();
    home->setUsername(username);
    home->show();
}

void MainWindow::on_downBtn_clicked()
{
    this->close();
}

void MainWindow::on_registerBtn_clicked()
{

}
