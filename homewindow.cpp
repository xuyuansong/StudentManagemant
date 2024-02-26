#include "homewindow.h"
#include "ui_homewindow.h"
#include "registerwindow.h"
#include "mainwindow.h"
#include "updatewindow.h"

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

}

void homeWindow::on_selectBtn_clicked()
{
    QMap<QString,QString> map={{"用户名","username"},{"性别","sex"},{"年龄","yearsold"},
                               {"专业班级","zhuanyeClass"},{"学号","xuehao"},{"家乡","home"},{"密码","password"}};

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
