#include "registerwindow.h"
#include "ui_registerwindow.h"

registerwindow::registerwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);

}

registerwindow::~registerwindow()
{
    delete ui;
}

void registerwindow::setDb(QSqlDatabase db)
{
    this->m_db = db;
}

void registerwindow::on_checkRegistBtn_clicked()
{
    if(ui->username->text().isEmpty() || ui->sex->text().isEmpty() || ui->age->text().isEmpty() ||
            ui->zhuanyeClass->text().isEmpty() || ui->home->text().isEmpty() || ui->xuehao->text().isEmpty() ||
            ui->password->text().isEmpty() || ui->checkPassword->text().isEmpty())
    {
        QMessageBox::warning(nullptr,"提示","请将信息填写完整");
    }else
    {
        if(ui->password->text() != ui->checkPassword->text())
        {
            ui->checkPassword->setText("");
            QMessageBox::warning(nullptr,"提示","两次输入的密码不相同");
        }
        QString username=ui->username->text();
        QSqlQuery query;
        QString selectSql="select *from student where username='"+username+"'";
        query.exec(selectSql);
        if(query.next())
        {
            QMessageBox::warning(nullptr,"警告","该用户已存在");
        }else
        {
            if(!this->m_db.open())
            {
                QMessageBox::warning(nullptr,"警告","连接数据库失败,无法注册用户");
            }
            QString insertSql="insert into student value('" + ui->username->text() + "','" + ui->sex->text() + "','" +
                    ui->age->text() + "','" + ui->zhuanyeClass->text() + "','" + ui->xuehao->text() + "','" + ui->home->text() +
                    "','" + ui->password->text() + "')";
            if(query.exec(insertSql))
            {
                QMessageBox::information(nullptr,"成功","注册成功");
                this->close();
            }else
            {
                QMessageBox::warning(nullptr,"警告","注册失败！");
            }
        }
    }
}
