#ifndef EMPERORWIN_H
#define EMPERORWIN_H

#include "order.h"
#include "hotelcheckorderwidget.h"

#include <QWidget>

namespace Ui {
class emperorwin;
}

class emperorwin : public QWidget
{
    Q_OBJECT

public:
    explicit emperorwin(QWidget *parent = 0);
    ~emperorwin();

    void getroom1wid();
    void getroom2wid();
    void getroom3wid();
    void getroom4wid();

private slots:
    void on_saveintroduction1_clicked();

    void on_setprice1_clicked();

    void on_setroom1_clicked();

    void on_checkorder1_clicked();

    void on_saveintroduction2_clicked();

    void on_setprice2_clicked();

    void on_setnumber2_clicked();

    void on_checkorder2_clicked();

    void on_saveitroduction3_clicked();

    void on_setprice3_clicked();

    void on_setnumber3_clicked();

    void on_checkorder3_clicked();

    void on_saveintroduction4_clicked();

    void on_setprice4_clicked();

    void on_setnumber4_clicked();

    void on_checkorder4_clicked();

    void on_logout_clicked();

private:
    Ui::emperorwin *ui;

    QVector<order> room1order;
    QVector<order> room2order;
    QVector<order> room3order;
    QVector<order> room4order;

    QVector<hotelcheckorderwidget*> room1wig;
    QVector<hotelcheckorderwidget*> room2wig;
    QVector<hotelcheckorderwidget*> room3wig;
    QVector<hotelcheckorderwidget*> room4wig;
};

#endif // EMPERORWIN_H
