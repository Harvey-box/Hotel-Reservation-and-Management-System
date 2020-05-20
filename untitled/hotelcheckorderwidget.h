#ifndef HOTELCHECKORDERWIDGET_H
#define HOTELCHECKORDERWIDGET_H

#include "order.h"

#include <QWidget>

namespace Ui {
class hotelcheckorderwidget;
}

class hotelcheckorderwidget : public QWidget
{
    Q_OBJECT

public:
    explicit hotelcheckorderwidget(int orderid, QWidget *parent = 0);
    ~hotelcheckorderwidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::hotelcheckorderwidget *ui;
    int thisID;
    order* thisorder;
};

#endif // HOTELCHECKORDERWIDGET_H
