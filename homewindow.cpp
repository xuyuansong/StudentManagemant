#include "homewindow.h"
#include "ui_homewindow.h"
#include "registerwindow.h"
#include "mainwindow.h"
#include "updatewindow.h"
#include "deletewindow.h"

homeWindow::homeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homeWindow)
{
    ui->setupUi(this);

    ui->welcomeLabel->setText("欢迎: ");

    ui->comboBox->addItem("用户名");
    ui->comboBox->addItem("性别");
    ui->comboBox->addItem("年龄");
    ui->comboBox->addItem("专业班级");
    ui->comboBox->addItem("学号");
    ui->comboBox->addItem("家乡");
    ui->comboBox->addItem("密码");

    ui->tableWidget->setColumnCount(6);
    QStringList headlist;
    headlist<<"姓名"<<"性别"<<"年龄"<<"专业班级"<<"学号"<<"家乡";
    ui->tableWidget->setHorizontalHeaderLabels(headlist);
}

homeWindow::~homeWindow()
{
    delete ui;
}

void homeWindow::setUsername(QString username)
{
    this->m_username=username;
    ui->usernameLabel->setText(m_username);
}

void homeWindow::on_insertBtn_clicked()
{
    if(m_username!="admin")
    {
        QMessageBox::warning(nullptr,"警告","需管理员才能添加用户");
    }else
    {
        registerwindow* reg = new registerwindow();
        reg->show();
    }
}


void homeWindow::on_deleteBtn_clicked()
{
    if(m_username=="admin")
    {
        deletewindow* del = new deletewindow();
        del->show();
    }else
    {
        QMessageBox::warning(nullptr,"警告","需管理员才能删除用户");
    }
}

void homeWindow::on_selectBtn_clicked()
{
    QMap<QString,QString> map={{"用户名","username"},{"性别","sex"},{"年龄","yearsold"},
                               {"专业班级","zhuanyeClass"},{"学号","xuehao"},{"家乡","home"},{"密码","password"}};
    ui->tableWidget->setRowCount(0);
    QString selectSql="select * from student where " + map[ui->comboBox->currentText()] + "='" + ui->lineEdit->text() + "'";
    QSqlQuery query;
    query.exec(selectSql);
    QStringList datalist;
    while(query.next())
    {
        for (int i = 0; i < 7; ++i) {
            datalist.append(query.value(i).toString());
            //qDebug()<<query.value(i).toString();
        }
    }

    int n = datalist.size()/7;
    for (int i = 0; i < n; ++i) {
        QStringList templist = datalist.mid(i*7,6);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for (int col = 0; col < templist.size(); ++col) {
            QTableWidgetItem *pItem = new QTableWidgetItem(templist[col]);
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,col,pItem);
        }
    }

}

void homeWindow::on_updateBtn_clicked()
{
    updatewindow* up = new updatewindow();
    up->setUsername(this->m_username);
    up->show();
}

void homeWindow::on_changeUserBtn_clicked()
{
    this->close();
    MainWindow* ma = new MainWindow();
    ma->show();
}
