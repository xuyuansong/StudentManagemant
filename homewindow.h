#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QWidget>
#include <QString>

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

private:
    Ui::homeWindow *ui;
    QString m_username;
};

#endif // HOMEWINDOW_H
