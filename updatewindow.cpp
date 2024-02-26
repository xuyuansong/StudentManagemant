#include "updatewindow.h"
#include "ui_updatewindow.h"

updatewindow::updatewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatewindow)
{
    ui->setupUi(this);

//    QMap<QString,QString> map={{"用户名","username"},{"性别","sex"},{"年龄","yearsold"},
//                               {"专业班级","zhuanyeClass"},{"学号","xuehao"},{"家乡","home"},{"密码","password"}};

    ui->comboBox->addItem("用户名");
    ui->comboBox->addItem("性别");
    ui->comboBox->addItem("年龄");
    ui->comboBox->addItem("专业班级");
    ui->comboBox->addItem("学号");
    ui->comboBox->addItem("家乡");
    ui->comboBox->addItem("密码");

}

updatewindow::~updatewindow()
{
    delete ui;
}

void updatewindow::setUsername(QString username)
{
    this->m_username=username;
}

void updatewindow::on_pushButton_clicked()
{
    QMap<QString,QString> map={{"用户名","username"},{"性别","sex"},{"年龄","yearsold"},
                               {"专业班级","zhuanyeClass"},{"学号","xuehao"},{"家乡","home"},{"密码","password"}};
    if(m_username=="admin" || m_username== ui->usernameEdit->text())
    {
        QString updateSql="update student set "+ map[ui->comboBox->currentText()] + "='" + ui->updateEdit->text() + "' " +
                "where username='" + ui->usernameEdit->text() + "'";
        qDebug()<<updateSql;
        QSqlQuery query;
        query.exec(updateSql);
    }else
    {
        QMessageBox::warning(nullptr,"警告","需管理员才能修改其他用户信息");
    }
}
