#include "alldata.h"
#include "mydatabase.h"

#include <QDebug>
#include <QVector>
#include <QMessageBox>
#include <QDate>

allData::allData()
{

}


QVector<hotel> allData::allHotel(0);
QVector<customer> allData::allCustomer(0);
QVector<hotelroom> allData::allRoom(0);
QVector<hotelroom> allData::LisboaRoom(0);
QVector<hotelroom> allData::ParisianRoom(0);
QVector<hotelroom> allData::VenetianRoom(0);
QVector<hotelroom> allData::EmperorRoom(0);
QVector<order> allData::allOrder(0);


/*----------------------------------------- set -----------------------------------------*/
void allData::setallHotel()
{
    myDatabase::getHotel(allHotel);
}

void allData::setallCustomer()
{
    myDatabase::getCustomer(allCustomer);
}

void allData::setallRoom()
{
    myDatabase::getRoom(allRoom);
}

void allData::setLisboaRoom()
{
    myDatabase::getRoom(LisboaRoom, "Lisboa");
}

void allData::setParisianRoom()
{
    myDatabase::getRoom(ParisianRoom, "Parisian");
}

void allData::setVenetianRoom()
{
    myDatabase::getRoom(VenetianRoom, "Venetian");
}

void allData::setEmperorRoom()
{
    myDatabase::getRoom(EmperorRoom, "Emperor");
}

void allData::setallOrder()
{
    myDatabase::getOrder(allOrder);
}


/*----------------------------------------- add -----------------------------------------*/
void allData::addCustomer(QString username, QString password)
{
    if(myDatabase::CreateCustomer(username, password, customer::CusNumber))
    {
        customer newcustomer(username, password);
        allCustomer.push_back(newcustomer);
        qDebug() << customer::CusNumber;
    }
}

void allData::addOrder(int newcustomerid, QString newroomid, QString newhotelname,
                       QString newroomtype, double newprice, QDate newstartdate, QDate newenddate)
{
    QDate now = QDate::currentDate();
    if(newstartdate > now)
    {
        order neworder(newcustomerid, newroomid, newhotelname, newroomtype, newprice, newstartdate, newenddate);
        allOrder.push_back(neworder);
        myDatabase::CreateOrder(neworder.getOrderID(), newcustomerid, newroomid,
                                newhotelname, newroomtype, newprice, newstartdate, newenddate);
        qDebug() << order::ordernum;
    }
    else
    {
        QMessageBox::critical(0,"WARNING","Please select right Date.", QMessageBox::Ok);
    }
}


/*----------------------------------------- get -----------------------------------------*/
QVector<hotel> *allData::getallHotel()
{
    return &allHotel;
}

QVector<customer>* allData::getallCustomer()
{
    return &allCustomer;
}

QVector<hotelroom> *allData::getallRoom()
{
    return &allRoom;
}

QVector<order>* allData::getallOrder()
{
    return &allOrder;
}

QVector<hotelroom>* allData::getLisboaRoom()
{
    return &LisboaRoom;
}

QVector<hotelroom>* allData::getParisianRoom()
{
    return &ParisianRoom;
}

QVector<hotelroom>* allData::getVenetianRoom()
{
    return &VenetianRoom;
}

QVector<hotelroom>* allData::getEmperorRoom()
{
    return &EmperorRoom;
}



int allData::getCustomerID(QString username)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if(allCustomer[i].getUsername() == username)
        {
            return allCustomer[i].getcustomerid();
        }
    }

    QMessageBox::critical(0,"WARNING","This user is not existed!",QMessageBox::Close);
    return 0;
}


QString allData::getCustomerUM(int ID)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if(allCustomer[i].getcustomerid() == ID)
        {
            return allCustomer[i].getUsername();
        }
    }

    QMessageBox::critical(0,"WARNING","This userID is not existed!",QMessageBox::Close);
    return 0;
}


QString allData::getCustomerPW(int ID)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if(allCustomer[i].getcustomerid() == ID)
        {
            return allCustomer[i].getPassword();
        }
    }

    QMessageBox::critical(0,"WARNING","This userID is not existed!",QMessageBox::Close);
    return 0;
}


void allData::getRoomData(QVector<hotelroom>& newRoomList, QString hotelname)
{
    hotelroom *newRoom;
    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getHotelName() == hotelname)
        {
            newRoom = new hotelroom;
            newRoom->addRoomData(hotelname, allRoom[i].getRoomType(), allRoom[i].getIntroduction(),
                                allRoom[i].getPrice(), allRoom[i].getAmount(), allRoom[i].getimage(),
                                allRoom[i].getid());
            newRoomList.push_back(*newRoom);
        }
    }
}


void allData::getRoomData(hotelroom &room, QString hotelname, QString roomtype)
{
    for(int i=0; i<allRoom.size(); i++)
    {
        if((allRoom[i].getHotelName() == hotelname) && (allRoom[i].getRoomType() == roomtype))
        {
            room = allRoom[i];
            break;
        }

        if(i == (allRoom.size()-1))
        {
            QMessageBox::critical(0,"WARNING","This type is not existed!",QMessageBox::Close);
        }
    }
}

int allData::getRoomOrderNum(QString roomID, QDate date)
{
    int num=0;
    for(int i=0; i<allOrder.size(); i++)
    {
        if((allOrder[i].getRoomID() == roomID) && (allOrder[i].getStatus() != "canceled")
                && (date >= allOrder[i].getStartDate()) && (date < allOrder[i].getEndDate()))
        {
            num++;
        }
    }
    return num;
}


unsigned int allData::getRoomAmount(int roomID)
{
    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getid() == roomID)
        {
            return allRoom[i].getAmount();
        }
    }
    QMessageBox::critical(0,"WARNING","This roomID is not existed!",QMessageBox::Close);
    return 0;
}


void allData::getOrder(QVector<order> &myorder, int newcumtomerID)
{
    order *neworder;
    int orderid;
    int customerid;
    QString roomid;
    QString hotelname;
    QString roomtype;
    double price;
    QDate start;
    QDate end;
    QString status;

    for(int i=0; i<allOrder.size(); i++)
    {
        if(allOrder[i].getCustomerID() == newcumtomerID)
        {
            orderid = allOrder[i].getOrderID();
            customerid = allOrder[i].getCustomerID();
            roomid = allOrder[i].getRoomID();
            hotelname = allOrder[i].gethotelname();
            roomtype = allOrder[i].getroomtype();
            price = allOrder[i].getprice();
            start = allOrder[i].getStartDate();
            end = allOrder[i].getEndDate();
            status = allOrder[i].getStatus();
            neworder = new order(orderid, customerid, roomid, hotelname, roomtype, price, start, end, status);
            myorder.push_back(*neworder);
        }
    }
}

\
void allData::getOrder(QVector<order> &myorder, QString newroomid)
{
    order *neworder;
    int orderid;
    int customerid;
    QString roomid;
    QString hotelname;
    QString roomtype;
    double price;
    QDate start;
    QDate end;
    QString status;

    for(int i=0; i<allOrder.size(); i++)
    {
        if(allOrder[i].getRoomID() == newroomid)
        {
            orderid = allOrder[i].getOrderID();
            customerid = allOrder[i].getCustomerID();
            roomid = allOrder[i].getRoomID();
            hotelname = allOrder[i].gethotelname();
            roomtype = allOrder[i].getroomtype();
            price = allOrder[i].getprice();
            start = allOrder[i].getStartDate();
            end = allOrder[i].getEndDate();
            status = allOrder[i].getStatus();
            neworder = new order(orderid, customerid, roomid, hotelname, roomtype, price, start, end, status);
            myorder.push_back(*neworder);
        }
    }
}


order *allData::getOrder(int orderID)
{
    for(int i=0; i<allOrder.size(); i++)
    {
        if(allOrder[i].getOrderID() == orderID)
        {
            return &allOrder[i];
        }
    }
    QMessageBox::critical(0,"WARNING","This OrderID is not exited!",QMessageBox::Close);
    return 0;
}




/*----------------------------------------- check -----------------------------------------*/
bool allData::checkHotelPW(QString check_username, QString check_password)
{
    for(int i=0; i<allHotel.size(); i++)
    {
        if((allHotel[i].getUsername() == check_username) && (allHotel[i].getPassword() == check_password))
        {
            return true;
        }
    }
    return false;
}

bool allData::checkCustomerPW(QString check_username, QString check_password)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if((allCustomer[i].getUsername() == check_username) && (allCustomer[i].getPassword() == check_password))
        {
            return true;
        }
    }
    return false;
}

bool allData::checkCustomerUser(QString username)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if(allCustomer[i].getUsername() == username)
        {
            return true;
        }
    }
    return false;
}


/*----------------------------------------- change -----------------------------------------*/
void allData::changeRoomData(QString selectHotelname, QString selectRoomtype, QString newIntroduction,
                             double newPrice, unsigned int newAmount, QString newImage, QString newid)
{
    myDatabase::ChangeRoomData(selectHotelname, selectRoomtype, newIntroduction, newPrice, newAmount, newImage, newid);

    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getHotelName() == selectHotelname && allRoom[i].getRoomType() == selectRoomtype)
        {
            allRoom[i].addRoomData(selectHotelname, selectRoomtype, newIntroduction, newPrice, newAmount, newImage, newid);
            break;
        }
    }

    if(selectHotelname == "Lisboa")
    {
        for(int i=0; i<LisboaRoom.size(); i++)
        {
            if(LisboaRoom[i].getRoomType() == selectRoomtype)
            {
                LisboaRoom[i].addRoomData(selectHotelname, selectRoomtype, newIntroduction, newPrice, newAmount, newImage, newid);
                break;
            }
        }
    }
}


void allData::changeRoomData(QString selectHotelname, QString selectRoomtype, QString newIntroduction)
{
    myDatabase::ChangeRoomData(selectHotelname, selectRoomtype, newIntroduction);

    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getHotelName() == selectHotelname && allRoom[i].getRoomType() == selectRoomtype)
        {
            allRoom[i].changeIntroduction(newIntroduction);
            break;
        }
    }

    if(selectHotelname == "Lisboa")
    {
        for(int i=0; i<LisboaRoom.size(); i++)
        {
            if(LisboaRoom[i].getRoomType() == selectRoomtype)
            {
                LisboaRoom[i].changeIntroduction(newIntroduction);
                break;
            }
        }
    }
}


void allData::changeRoomData(QString selectHotelname, QString selectRoomtype, double newPrice)
{
    myDatabase::ChangeRoomData(selectHotelname, selectRoomtype, newPrice);

    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getHotelName() == selectHotelname && allRoom[i].getRoomType() == selectRoomtype)
        {
            allRoom[i].changePrice(newPrice);
            break;
        }
    }

    if(selectHotelname == "Lisboa")
    {
        for(int i=0; i<LisboaRoom.size(); i++)
        {
            if(LisboaRoom[i].getRoomType() == selectRoomtype)
            {
                LisboaRoom[i].changePrice(newPrice);
                break;
            }
        }
    }
}


void allData::changeRoomData(QString selectHotelname, QString selectRoomtype, unsigned int newAmount)
{
    myDatabase::ChangeRoomData(selectHotelname, selectRoomtype, newAmount);

    for(int i=0; i<allRoom.size(); i++)
    {
        if(allRoom[i].getHotelName() == selectHotelname && allRoom[i].getRoomType() == selectRoomtype)
        {
            allRoom[i].changeAmount(newAmount);
            break;
        }
    }

    if(selectHotelname == "Lisboa")
    {
        for(int i=0; i<LisboaRoom.size(); i++)
        {
            if(LisboaRoom[i].getRoomType() == selectRoomtype)
            {
                LisboaRoom[i].changeAmount(newAmount);
                break;
            }
        }
    }
}

void allData::changeUserPW(QString username, QString newpassword)
{
    for(int i=0; i<allCustomer.size(); i++)
    {
        if(allCustomer[i].getUsername() == username)
        {
            allCustomer[i].changePW(newpassword);
            myDatabase::ChangeCustomerPW(username, newpassword);
            QMessageBox::information(0,"NOTICE", "Change Password success.", QMessageBox::Close);
            break;
        }
    }
}


/*----------------------------------------- cancel -----------------------------------------*/
void allData::cancelOrder(int orderid)
{
    QDate now = QDate::currentDate();
    for(int i=0; i<allOrder.size(); i++)
    {
        if(allOrder[i].getOrderID() == orderid)
        {
            if(allOrder[i].getStartDate() > now)
            {
                allOrder[i].changeOrderStatus("canceled");
                myDatabase::ChangeOrderStatus(orderid, "canceled");
                QMessageBox::information(0,"NOTICE","Your order has been canceled.",QMessageBox::Ok);
            }else
            {
                QMessageBox::critical(0,"WARNING","This order has expired.",QMessageBox::Ok);
            }
            break;
        }
    }
}


/*----------------------------------------- cancel -----------------------------------------*/
void allData::updateOrderStatus()
{
    QDate now = QDate::currentDate();
    for(int i=0; i<allOrder.size(); i++)
    {
        if(allOrder[i].getStartDate() <= now)
        {
            myDatabase::UpdateOrderStatus(allOrder[i].getOrderID());
            allOrder[i].changeOrderStatus("expired");
        }
    }
}



/*----------------------------------------- show -----------------------------------------*/
void allData::showdata()
{
    qDebug() << "HOTEL";
    for(int i=0; i<allHotel.size(); i++)
      {
          qDebug() << allHotel[i].getUsername() << allHotel[i].getPassword();
      }
    qDebug() << endl;

    qDebug() << "CUSTOMER";
    for(int i=0; i<allCustomer.size(); i++)
      {
          qDebug() << allCustomer[i].getUsername() << allCustomer[i].getPassword() << allCustomer[i].getcustomerid();
      }
    qDebug() << endl;

    qDebug() << "ROOM";
    for(int i=0; i<allRoom.size(); i++)
      {
          qDebug() << allRoom[i].getHotelName() << allRoom[i].getRoomType() << allRoom[i].getIntroduction()
                   << allRoom[i].getPrice() << allRoom[i].getAmount() << allRoom[i].getimage() << allRoom[i].getid();
      }
    qDebug() << endl;

    qDebug() << "ORDER";
    for(int i=0; i<allOrder.size(); i++)
    {
        qDebug() << allOrder[i].getOrderID() << allOrder[i].getCustomerID() << allOrder[i].getRoomID()
                 << allOrder[i].gethotelname() << allOrder[i].getroomtype() << allOrder[i].getprice()
                 << allOrder[i].getStartDate() << allOrder[i].getEndDate() << allOrder[i].getStatus();
    }

    qDebug() << "CUSTOMERNUM" << customer::CusNumber;
    qDebug() << "ORDERNUM" << order::ordernum;
}

void allData::showdata(QString hotelname)
{
    qDebug() << hotelname;
    if(hotelname == "Lisboa")
    {
        for(int i=0; i<LisboaRoom.size(); i++)
          {
            qDebug() << LisboaRoom[i].getHotelName() << LisboaRoom[i].getRoomType() << LisboaRoom[i].getIntroduction()
                     << LisboaRoom[i].getPrice() << LisboaRoom[i].getAmount() << LisboaRoom[i].getimage() << LisboaRoom[i].getid();
          }
    }
}
