#ifndef CUSTOMERWIN_H
#define CUSTOMERWIN_H

#include "hoteldata.h"
#include "roomforcustomer.h"

#include <QWidget>
#include <QAction>

namespace Ui {
class customerwin;
}

class customerwin : public QWidget
{
    Q_OBJECT

public:
    explicit customerwin(QString username, int id, QWidget *parent = 0);
    ~customerwin();

    void getRoomWid();
    QVector<roomforcustomer*> allRoomWid;
private slots:
    void on_UserButton_clicked();

    void on_pushButton_clicked();

    void allhotel();
    void Lisboa();
    void Parisian();
    void Venetian();
    void Emperor();

    void slotup();
    void slotdown();

private:
    Ui::customerwin *ui;
    QVector<hotelroom> allRoomData;
    QAction* act[5];
    QAction* slot[2];
    QString myusername;
    int userid;
};

#endif // CUSTOMERWIN_H
