#ifndef USERORDER_H
#define USERORDER_H

#include "order.h"

#include <QWidget>
#include <QVector>

namespace Ui {
class userorder;
}

class userorder : public QWidget
{
    Q_OBJECT

public:
    explicit userorder(int customerid, QWidget *parent = 0);
    ~userorder();

private:
    Ui::userorder *ui;
    int mycustomerid;    QVector<order> myorder;
};

#endif // USERORDER_H
