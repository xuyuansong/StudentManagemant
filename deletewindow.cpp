#include "deletewindow.h"
#include "ui_deletewindow.h"

deletewindow::deletewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deletewindow)
{
    ui->setupUi(this);
}

deletewindow::~deletewindow()
{
    delete ui;
}

void deletewindow::on_pushButton_clicked()
{
    QSqlQuery query;
    QString selectSql="select * from student where username='" + ui->lineEdit->text() + "'";
    QString deleteSql="delete from student where username='" + ui->lineEdit->text() + "'";
    query.exec(selectSql);
    if(query.next() && query.value("username").toString() == ui->lineEdit->text())
    {
        query.exec(deleteSql);
        QMessageBox::information(nullptr,"提示","删除成功");
        this->close();
    }else
    {
        QMessageBox::warning(nullptr,"警告","删除失败,请检查用户名是否输入正确或存在!");
    }
}
