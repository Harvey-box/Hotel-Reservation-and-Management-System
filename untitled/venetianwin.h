#ifndef VENETIANWIN_H
#define VENETIANWIN_H

#include "order.h"
#include "hotelcheckorderwidget.h"

#include <QWidget>

namespace Ui {
class venetianwin;
}

class venetianwin : public QWidget
{
    Q_OBJECT

public:
    explicit venetianwin(QWidget *parent = 0);
    ~venetianwin();

    void getroom1wid();
    void getroom2wid();
    void getroom3wid();
    void getroom4wid();
    void getroom5wid();

private slots:
    void on_saveintroduction1_5_clicked();

    void on_saveintroduction2_5_clicked();

    void on_saveitroduction3_5_clicked();

    void on_saveintroduction4_5_clicked();

    void on_saveintroduction4_6_clicked();

    void on_setprice1_5_clicked();

    void on_setprice2_5_clicked();

    void on_setprice3_5_clicked();

    void on_setprice4_5_clicked();

    void on_setprice4_6_clicked();

    void on_setroom1_5_clicked();

    void on_setnumber2_5_clicked();

    void on_setnumber3_5_clicked();

    void on_setnumber4_5_clicked();

    void on_setnumber4_6_clicked();

    void on_checkorder4_6_clicked();

    void on_checkorder1_5_clicked();

    void on_checkorder2_5_clicked();

    void on_checkorder3_5_clicked();

    void on_checkorder4_5_clicked();

    void on_logout_5_clicked();

private:
    Ui::venetianwin *ui;

    QVector<order> room1order;
    QVector<order> room2order;
    QVector<order> room3order;
    QVector<order> room4order;
    QVector<order> room5order;
    QVector<hotelcheckorderwidget*> room1wig;
    QVector<hotelcheckorderwidget*> room2wig;
    QVector<hotelcheckorderwidget*> room3wig;
    QVector<hotelcheckorderwidget*> room4wig;
    QVector<hotelcheckorderwidget*> room5wig;
};

#endif // VENETIANWIN_H
