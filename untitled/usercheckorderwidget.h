#ifndef USERCHECKORDERWIDGET_H
#define USERCHECKORDERWIDGET_H

#include "order.h"

#include <QWidget>

namespace Ui {
class usercheckorderwidget;
}

class usercheckorderwidget : public QWidget
{
    Q_OBJECT

public:
    explicit usercheckorderwidget(int orderID, QWidget *parent = 0);
    ~usercheckorderwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usercheckorderwidget *ui;
    order* thisorder;
    int thisID;
};

#endif // USERCHECKORDERWIDGET_H
