#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class deletewindow;
}

class deletewindow : public QWidget
{
    Q_OBJECT

public:
    explicit deletewindow(QWidget *parent = nullptr);
    ~deletewindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletewindow *ui;
};

#endif // DELETEWINDOW_H
