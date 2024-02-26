#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void enterApp(QString username);

private slots:
    void on_downBtn_clicked();

    void on_LoginBtn_clicked();

    void on_registerBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
