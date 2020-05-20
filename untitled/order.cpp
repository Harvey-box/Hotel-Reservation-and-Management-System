#include "order.h"
#include "mydatabase.h"

int order::ordernum = 0;

order::order()
{

}

order::order(int newIDC, QString newIDR, QString newhotelname, QString newroomtype, double newprice, QDate in, QDate out)
{
    OrderID = ordernum;
    CustomerID = newIDC;
    RoomID = newIDR;
    hotelname = newhotelname;
    roomtype = newroomtype;
    price = newprice;
    StartDate = in;
    EndDate = out;
    status = "effect";
}

order::order(int newIDO, int newIDC, QString newIDR, QString newhotelname,
             QString newroomtype, double newprice, QDate in, QDate out, QString newstatus)
{
    OrderID = newIDO;
    CustomerID = newIDC;
    RoomID = newIDR;
    hotelname = newhotelname;
    roomtype = newroomtype;
    price = newprice;
    StartDate = in;
    EndDate = out;
    status = newstatus;
}

void order::addData(int newIDO, int newIDC, QString newIDR, QString newhotelname,
                    QString newroomtype, double newprice, QDate in, QDate out, QString newstatus)
{
    OrderID = newIDO;
    CustomerID = newIDC;
    RoomID = newIDR;
    hotelname = newhotelname;
    roomtype = newroomtype;
    price = newprice;
    StartDate = in;
    EndDate = out;
    status = newstatus;
}


int order::getOrderID()
{
    return OrderID;
}

int order::getCustomerID()
{
    return CustomerID;
}

QString order::getRoomID()
{
    return RoomID;
}

QString order::gethotelname()
{
    return hotelname;
}

QString order::getroomtype()
{
    return roomtype;
}

double order::getprice()
{
    return price;
}

QDate order::getStartDate()
{
    return StartDate;
}

QDate order::getEndDate()
{
    return EndDate;
}

QString order::getStatus()
{
    return status;
}

void order::changeOrderStatus(QString newstatus)
{
    status = newstatus;
}
