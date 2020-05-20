#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include "order.h"

#include <QWidget>

namespace Ui {
class orderwidget;
}

class orderwidget : public QWidget
{
    Q_OBJECT

public:
    explicit orderwidget(order neworder, QWidget *parent = 0);
    ~orderwidget();

private:
    Ui::orderwidget *ui;
    order myorder;
};

#endif // ORDERWIDGET_H
