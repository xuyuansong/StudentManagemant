#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H

#include <QWidget>
#include <QMap>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class updatewindow;
}

class updatewindow : public QWidget
{
    Q_OBJECT

public:
    explicit updatewindow(QWidget *parent = nullptr);
    ~updatewindow();

    void setUsername(QString username);

private slots:
    void on_pushButton_clicked();

private:
    Ui::updatewindow *ui;
    QString m_username;
};

#endif // UPDATEWINDOW_H
