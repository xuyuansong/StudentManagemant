#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDebug>

namespace Ui {
class registerwindow;
}

class registerwindow : public QWidget
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

    void setDb(QSqlDatabase db);

private slots:
    void on_checkRegistBtn_clicked();

private:
    Ui::registerwindow *ui;

    QSqlDatabase m_db;
};

#endif // REGISTERWINDOW_H
