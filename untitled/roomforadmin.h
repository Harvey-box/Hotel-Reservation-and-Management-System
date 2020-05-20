#ifndef ROOMFORADMIN_H
#define ROOMFORADMIN_H

#include <QWidget>

namespace Ui {
class roomforadmin;
}

class roomforadmin : public QWidget
{
    Q_OBJECT

public:
    explicit roomforadmin(QWidget *parent, QString newHotelName, QString newRoomType,
                          QString newRoomIntroduction, double newRoomPrice, unsigned int newRoomAmount
                          , QString newImageAddress, QString newroomid);
    ~roomforadmin();

private:
    Ui::roomforadmin *ui;
    QString HotelName;
    QString RoomType;
    QString RoomIntroduction;
    double RoomPrice;
    unsigned int RoomAmount;
    QString ImageAddress;
    QString RoomID;
};

#endif // ROOMFORADMIN_H
