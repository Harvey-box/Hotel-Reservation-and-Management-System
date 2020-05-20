#ifndef ADMINWIN_H
#define ADMINWIN_H

#include "hoteldata.h"
#include "roomforadmin.h"
#include "usercheckorderwidget.h"

#include <QWidget>
#include <QVector>

namespace Ui {
class adminwin;
}

class adminwin : public QWidget
{
    Q_OBJECT

public:
    explicit adminwin(QWidget *parent = 0);
    ~adminwin();
    void getRoomWid();
    void getmyOrderWin();

private:
    Ui::adminwin *ui;
    QVector<hotelroom> allRoomData;
    QVector<roomforadmin*> allRoomWid;
    QVector<usercheckorderwidget*> myorderwin;
    QVector<order> myallorder;
};

#endif // ADMINWIN_H
