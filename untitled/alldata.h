#ifndef ALLDATA_H
#define ALLDATA_H

#include "people.h"
#include "hoteldata.h"
#include "order.h"

#include <QVector>

class allData
{
public:
    allData();

    static void setallHotel();                                                                          //從數據庫獲取全部hotel資料
    static void setallCustomer();                                                                       //從數據庫獲取全部customer資料
    static void setallRoom();                                                                           //從數據庫獲取全部room資料
    static void setLisboaRoom();                                                                        //從數據庫獲取全部Lisboa的room資料
    static void setParisianRoom();                                                                      //從數據庫獲取全部Parisian的room資料
    static void setVenetianRoom();                                                                      //從數據庫獲取全部Venetian的room資料
    static void setEmperorRoom();                                                                       //從數據庫獲取全部Emperor的room資料
    static void setallOrder();                                                                          //從數據庫獲取全部order資料
    static void addCustomer(QString username, QString password);
    static void addOrder(int newcustomerid, QString newroomid, QString newhotelname,
                         QString newroomtype, double price, QDate newstartdate, QDate newenddate);

    static QVector<hotel>* getallHotel();
    static QVector<customer>* getallCustomer();
    static QVector<hotelroom>* getallRoom();
    static QVector<order>* getallOrder();
    static QVector<hotelroom>* getLisboaRoom();
    static QVector<hotelroom>* getParisianRoom();
    static QVector<hotelroom>* getVenetianRoom();
    static QVector<hotelroom>* getEmperorRoom();
    static int getCustomerID(QString username);
    static QString getCustomerUM(int ID);
    static QString getCustomerPW(int ID);
    static void getRoomData(QVector<hotelroom> &newRoomList, QString hotelname);
    static void getRoomData(hotelroom& room, QString hotelname, QString roomtype);
    static int getRoomOrderNum(QString roomID, QDate date);
    static unsigned int getRoomAmount(int roomID);
    static void getOrder(QVector<order> &myorder, int cumtomerID);
    static void getOrder(QVector<order> &myorder, QString newroomid);
    static order* getOrder(int orderID);

    static bool checkHotelPW(QString check_username, QString check_password);
    static bool checkCustomerUser(QString username);
    static bool checkCustomerPW(QString check_username, QString check_password);
    static bool checkRoomNum(int roomid, QDate date);

    static void changeRoomData(QString selectHotelname, QString selectRoomtype, QString newIntroduction,
                               double newPrice, unsigned int newAmount, QString newImage, QString newid);
    static void changeRoomData(QString selectHotelname, QString selectRoomtype, QString newIntroduction);
    static void changeRoomData(QString selectHotelname, QString selectRoomtype, double newPrice);
    static void changeRoomData(QString selectHotelname, QString selectRoomtype, unsigned int newAmount);
    static void changeUserPW(QString username, QString newpassword);

    static void cancelOrder(int orderid);
    static void updateOrderStatus();

    static void showdata();
    static void showdata(QString hotelname);

private:
    static QVector<hotel> allHotel;
    static QVector<customer> allCustomer;
    static QVector<hotelroom> allRoom;
    static QVector<hotelroom> LisboaRoom;
    static QVector<hotelroom> ParisianRoom;
    static QVector<hotelroom> VenetianRoom;
    static QVector<hotelroom> EmperorRoom;
    static QVector<order> allOrder;
};

#endif // ALLDATA_H
