#ifndef USERINFORMATION_H
#define USERINFORMATION_H

#include "usercheckorderwidget.h"
#include "order.h"

#include <QWidget>
#include <QVector>

namespace Ui {
class userinformation;
}

class userinformation : public QWidget
{
    Q_OBJECT

public:
    explicit userinformation(QString username, int id, QWidget *parent = 0);
    ~userinformation();
    void getmyOrderWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::userinformation *ui;

    QVector<usercheckorderwidget*> myorderwin;
    QVector<order> myallorder;
    QString myUserName;
    int myUserID;
};

#endif // USERINFORMATION_H
