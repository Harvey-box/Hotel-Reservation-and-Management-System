#include "hoteldata.h"

hoteldata::hoteldata()
{

}


hotelroom::hotelroom()
{

}

void hotelroom::addRoomData(QString newHotelName, QString newRoomType, QString newIntroduction,
                            double newPrice, unsigned int newAmount, QString newimage, QString newid)
{
    HotelName = newHotelName;
    RoomType = newRoomType;
    Introduction = newIntroduction;
    Price = newPrice;
    Amount = newAmount;
    imageAddress = newimage;
    ID = newid;
}

void hotelroom::changeIntroduction(QString newIntroduction)
{
    Introduction = newIntroduction;
}

void hotelroom::changePrice(double newPrice)
{
    Price = newPrice;
}

void hotelroom::changeAmount(unsigned int newAmount)
{
    Amount = newAmount;
}


QString hotelroom::getHotelName()
{
    return HotelName;
}

QString hotelroom::getIntroduction()
{
    return Introduction;
}

QString hotelroom::getRoomType()
{
    return RoomType;
}

double hotelroom::getPrice()
{
    return Price;
}

unsigned int hotelroom::getAmount()
{
    return Amount;
}

QString hotelroom::getimage()
{
    return imageAddress;
}

QString hotelroom::getid()
{
    return ID;
}
