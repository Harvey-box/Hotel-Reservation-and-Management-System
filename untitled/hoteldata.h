#ifndef HOTELDATA_H
#define HOTELDATA_H

#include <QString>

class hoteldata
{
public:
    hoteldata();
protected:
    QString HotelName;
};


class hotelroom : public hoteldata
{
public:
    hotelroom();
    void addRoomData(QString newHotelName, QString newRoomType, QString newIntroduction,
                     double newPrice, unsigned int newAmount, QString newimage, QString newid);
    QString getHotelName();
    QString getRoomType();
    QString getIntroduction();
    double getPrice();
    unsigned int getAmount();
    QString getimage();
    QString getid();

    void changeIntroduction(QString newIntroduction);
    void changePrice(double newPrice);
    void changeAmount(unsigned int newAmount);

private:
    QString RoomType;
    QString Introduction;
    double Price;
    unsigned int Amount;
    QString imageAddress;
    QString ID;
};

#endif // HOTELDATA_H
