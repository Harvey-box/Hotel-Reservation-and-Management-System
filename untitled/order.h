#ifndef ORDER_H
#define ORDER_H

#include <QDate>

class order
{
public:
    order();
    order(int newIDC, QString newIDR, QString newhotelname, QString newroomtype
          , double newprice, QDate in, QDate out);
    order(int newIDO, int newIDC, QString newIDR, QString newhotelname,
          QString newroomtype, double newprice, QDate in, QDate out, QString newstatus);

    void addData(int newIDO, int newIDC, QString newIDR, QString newhotelname,
                 QString newroomtype, double newprice, QDate in, QDate out, QString newstatus);
    int getOrderID();
    int getCustomerID();
    QString gethotelname();
    QString getroomtype();
    double getprice();
    QString getRoomID();
    QDate getStartDate();
    QDate getEndDate();
    QString getStatus();
    static int ordernum;
    void changeOrderStatus(QString newstatus);

private:
    int OrderID;
    int CustomerID;
    QString RoomID;
    QString hotelname;
    QString roomtype;
    double price;
    QDate StartDate;
    QDate EndDate;
    QString status;
};

#endif // ORDER_H
