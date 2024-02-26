#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

namespace Ui {
class homeWindow;
}

class homeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit homeWindow(QWidget *parent = nullptr);
    ~homeWindow();

    void setUsername(QString username);

private slots:
    void on_insertBtn_clicked();

    void on_deleteBtn_clicked();

    void on_selectBtn_clicked();

    void on_updateBtn_clicked();

    void on_changeUserBtn_clicked();

private:
    Ui::homeWindow *ui;
    QString m_username;
};

#endif // HOMEWINDOW_H
