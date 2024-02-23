#include "homewindow.h"
#include "ui_homewindow.h"

homeWindow::homeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::homeWindow)
{
    ui->setupUi(this);

    ui->welcomeLabel->setText("欢迎: ");
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
