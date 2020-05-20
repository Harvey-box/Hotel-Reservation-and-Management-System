#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "people.h"
#include "hoteldata.h"
#include "order.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVector>
#include <QDate>

class myDatabase
{
public:
    myDatabase();
    static void ConnectDatabase();                                      //用於連接數據庫(7/27建立)
    static void setNumber();
    static bool SearchAdminData();
    static bool SearchHotelData(QString hotelname);
    static bool SearchCustomerData(QString customername);
    static bool SearchRoomData(QString hotelname, QString roomtype);
    static void CreateAdministrator();                                  //建立管理員帳戶(7/27建立)
    static void CreateHotel(QString username, QString password);        //插入數據到hotel(7/28建立)
    static bool CreateCustomer(QString username, QString password, int id);     //插入數據到customer(7/28建立)
    static void CreateOrder(int orderid, int customerid, QString roomid, QString hotelname,
                            QString roomtype, double price, QDate startdate, QDate enddate);
    static void DeleteData(QString username);                           //根據用戶名刪除數據(7/27建立)
    static void ShowData();                                             //用於顯示數據庫資料(7/27建立)
    static void getHotel(QVector<hotel>& allHotel);                      //取出數據庫中的所有hotel(7/28建立)
    static void getCustomer(QVector<customer>& allCustomer);             //取出數據庫中的所有customer(7/29建立)
    static int getCustomerNum();

    static void CreateHotelRoom(QString setHotelName, QString setRoomType, QString setIntroduction,
                                double setPrice, unsigned int setAmount, QString imageAddress, QString id);
    static void ChangeRoomData(QString newHotelName, QString newRoomType, QString newIntroduction,
                               double newPrice, unsigned int newAmount, QString newImage, QString id);
    static void ChangeRoomData(QString newHotelName, QString newRoomType, QString newIntroduction);
    static void ChangeRoomData(QString newHotelName, QString newRoomType, double newPrice);
    static void ChangeRoomData(QString newHotelName, QString newRoomType, unsigned int newAmount);
    static void UpdateOrderStatus(int orderid);
    static void ChangeOrderStatus(int orderid, QString newstatus);
    static void ChangeCustomerPW(QString username, QString newpassword);
    static void getRoom(QVector<hotelroom>& allRoom);
    static void getRoom(QVector<hotelroom>& Room, QString findHotelName);
    static void getOrder(QVector<order>& allOrder);
    static void getOrder(QVector<order> &Order, QString findHotelName);
    static int getOrderNum();
};

#endif // MYDATABASE_H
