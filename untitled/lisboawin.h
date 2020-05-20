#ifndef LISBOAWIN_H
#define LISBOAWIN_H

#include "hoteldata.h"
#include "order.h"
#include "hotelcheckorderwidget.h"
#include "alldata.h"

#include <QWidget>

namespace Ui {
class lisboawin;
}

class lisboawin : public QWidget
{
    Q_OBJECT

public:
    explicit lisboawin(QWidget *parent = 0);
    ~lisboawin();

    void getroom1wid();
    void getroom2wid();
    void getroom3wid();
    void getroom4wid();
    void getroom5wid();
    void getroom6wid();

private slots:
    void on_Lsaveintroduction_Superior_clicked();

    void on_Lsetprice_Superior_clicked();

    void on_Lsetrooms_Superior_clicked();

    void on_Lsaveintroduction_Deluxe_clicked();

    void on_Lsetprice_Deluxe_clicked();

    void on_Lsetrooms_Deluxe_clicked();

    void on_Lsaveintroduction_SuperiorLakeView_clicked();

    void on_Lsetprice_SuperiorLakeView_clicked();

    void on_Lsetrooms_SuperiorLakeView_clicked();

    void on_Lsaveintroduction_Corner_clicked();

    void on_Lsetprice_Corner_clicked();

    void on_Lsetrooms_Corner_clicked();

    void on_Lsaveintroduction_PremierDeluxe_clicked();

    void on_Lsetprice_PremierDeluxe_clicked();

    void on_Lsetrooms_PremierDeluxe_clicked();

    void on_Lsaveintroduction_PremierLakeView_clicked();

    void on_Lsetprice_PremierLakeView_clicked();

    void on_Lsetrooms_PremierLakeView_clicked();

    void on_checkButton_1_clicked();

    void on_pushButton_clicked();

    void on_checkButton_2_clicked();

    void on_checkButton_3_clicked();

    void on_checkButton_4_clicked();

    void on_checkButton_5_clicked();

    void on_checkButton_6_clicked();

private:
    Ui::lisboawin *ui;
    QVector<order> room1order;
    QVector<order> room2order;
    QVector<order> room3order;
    QVector<order> room4order;
    QVector<order> room5order;
    QVector<order> room6order;
    QVector<hotelcheckorderwidget*> room1wig;
    QVector<hotelcheckorderwidget*> room2wig;
    QVector<hotelcheckorderwidget*> room3wig;
    QVector<hotelcheckorderwidget*> room4wig;
    QVector<hotelcheckorderwidget*> room5wig;
    QVector<hotelcheckorderwidget*> room6wig;
};

#endif // LISBOAWIN_H
