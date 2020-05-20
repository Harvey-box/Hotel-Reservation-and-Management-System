#include "mydatabase.h"
#include "people.h"
#include "order.h"

#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include <QVariant>
#include <QDebug>

myDatabase::myDatabase()
{

}

/*---------------------------------------- ConnectDatabase ----------------------------------------*/
void myDatabase::ConnectDatabase()
{
    QSqlDatabase myDatabase = QSqlDatabase::addDatabase("QSQLITE");                             //連接數據庫SQLITE
    myDatabase.setDatabaseName("myDatabase.db");                                               //命名數據庫
    if(!myDatabase.open())                                                                      //打開數據庫並檢查是否正常打開
    {
        QMessageBox::critical(0,"WARNING!!!","DATABASE ERROR!!!",QMessageBox::Close);
    }

    QSqlQuery query;
    query.exec("create table administrator(username varchar(8), password varchar(12))");        //建立一個名為people的表格
    query.exec("create table hotel(username_h varchar(8), password_h varchar(12))");            //建立一個名為hotel的表格
    query.exec("create table customer(username_c varchar(8), password_c varchar(12), id_c int)");         //建立一個名為customer的表格
    query.exec("create table room(hotelname varchar(8), roomtype varchar(20), introduction varchar(150),"   //建立一個名為room的表格
               " price double, amount unsigned int, image varchar(50), id varchar(2))");
    query.exec("create table myo(oid int, customerid int, roomid varchar(2), hotelname_o varchar(8),"
               " roomtype_o varchar(20), price_o double, startdate varchar(10), enddate varchar(10), status varchar(8))");
    query.exec("create table num(cnum int, rnum int, onum int, idn int)");
}



/*---------------------------------------- SearchAdminData ----------------------------------------*/
void myDatabase::setNumber()
{
    QSqlQuery query;
    query.exec(QString("insert into num(cnum, rnum, onum, idn) values('0', '0', '0', '1')"));
}



/*---------------------------------------- SearchAdminData ----------------------------------------*/
bool myDatabase::SearchAdminData()
{
    QSqlQuery query;
    QString str;
    query.exec(QString("select * from Admin"));          //搜索customer裏是否存在要搜索的值
    query.next();                                                                                           //令query指向下一條,即要搜索的值所在位置
    str = query.value(0).toString();                                                                        //把值賦與str

    if(str == "Admin")                                                                                     //判斷數據庫裏是否存在要搜索的值
    {
        return true;                                                                                        //表示存在
    }

    return false;
}


/*---------------------------------------- SearchHotelData ----------------------------------------*/
bool myDatabase::SearchHotelData(QString hotelname)
{
    QSqlQuery query;
    QString str;
    query.exec(QString("select * from hotel where username_h = '%1'").arg(hotelname));          //搜索customer裏是否存在要搜索的值
    query.next();                                                                                           //令query指向下一條,即要搜索的值所在位置
    str = query.value(0).toString();                                                                        //把值賦與str

    if(str == hotelname)                                                                                     //判斷數據庫裏是否存在要搜索的值
    {
        return true;                                                                                        //表示存在
    }

    return false;
}



/*---------------------------------------- SearchCustomerData ----------------------------------------*/
bool myDatabase::SearchCustomerData(QString customername)
{
    QSqlQuery query;
    QString str;
    query.exec(QString("select * from hotel where username_c = '%1'").arg(customername));          //搜索customer裏是否存在要搜索的值
    query.next();                                                                                           //令query指向下一條,即要搜索的值所在位置
    str = query.value(0).toString();                                                                        //把值賦與str

    if(str == customername)                                                                                     //判斷數據庫裏是否存在要搜索的值
    {
        return true;                                                                                        //表示存在
    }

    return false;
}



/*---------------------------------------- SearchData ----------------------------------------*/
bool myDatabase::SearchRoomData(QString hotelname, QString roomtype)
{
    QSqlQuery query;
    query.exec(QString("select * from room where hotelname = '%1' and roomtype = '%2'").arg(hotelname).arg(roomtype));          //搜索customer裏是否存在要搜索的值
    query.next();                                                                                           //令query指向下一條,即要搜索的值所在位置
    QString str = query.value(0).toString();                                                                //把值賦與str及str2
    QString str2 = query.value(1).toString();

    if(str == hotelname && str2 == roomtype)                                                                //判斷數據庫裏是否存在要搜索的值
    {
        return true;                                                                                        //表示存在
    }

    return false;                                                                                           //表示不存在
}




/*---------------------------------------- CreateAdministrator ----------------------------------------*/
void myDatabase::CreateAdministrator()
{
    QSqlQuery query;
    if(!SearchAdminData())                                                                //判斷是否存在管理員,不存在才建立
    {
        query.exec("insert into administrator(username, password) values('Admin','password')");
        QMessageBox::information(0,"Notice","Create Admin Success",QMessageBox::Close);
    }else
    {
        QMessageBox::critical(0,"Notice","Admin has existed",QMessageBox::Close);
    }

}



/*---------------------------------------- CreateHotel ----------------------------------------*/
void myDatabase::CreateHotel(QString username, QString password)
{
    QSqlQuery query;
    if(!SearchHotelData(username))
    {
        query.exec(QString("insert into hotel(username_h, password_h) values('%1','%2')").arg(username).arg(password));
        QMessageBox::information(0,"Notice","Create Hotel Success",QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(0,"Warning","This Hotel has existed, please input a new one.",QMessageBox::Ok);
    }
}



/*---------------------------------------- CreateCustomer ----------------------------------------*/
bool myDatabase::CreateCustomer(QString username, QString password, int id)
{
    QSqlQuery query;
    if(!SearchCustomerData(username))
    {
        query.exec(QString("insert into customer(username_c, password_c, id_c) values('%1','%2','%3')")
                   .arg(username).arg(password).arg(id));
        query.exec(QString("update num set cnum = '%1' where idn = '%2'").arg((++customer::CusNumber)).arg(1));
        QMessageBox::information(0,"Notice","Create Customer Success",QMessageBox::Close);
        return true;
    }
    else
    {
        QMessageBox::critical(0,"Warning","This UserName has existed, please input a new one.",QMessageBox::Ok);
        return false;
    }
}



/*---------------------------------------- CreateOrder ----------------------------------------*/
void myDatabase::CreateOrder(int orderid, int customerid, QString roomid, QString hotelname,
                             QString roomtype, double price, QDate startdate, QDate enddate)
{
    QSqlQuery query;
    query.exec(QString("insert into myo(oid, customerid, roomid, hotelname_o, roomtype_o,"
                       " price_o, startdate, enddate, status) values('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', 'effect')")
               .arg(orderid).arg(customerid).arg(roomid).arg(hotelname).arg(roomtype).arg(price)
               .arg(startdate.toString("yyyy-MM-dd")).arg(enddate.toString("yyyy-MM-dd")));
    query.exec(QString("update num set onum = '%1' where idn = '%2'").arg((++order::ordernum)).arg(1));
    QMessageBox::information(0,"Notice","Create Order Success",QMessageBox::Close);
}



/*---------------------------------------- DeleteData ----------------------------------------*/
void myDatabase::DeleteData(QString username)
{
    QSqlQuery query;

    //執行刪除動作及判斷刪除動作是否成功
    if(query.exec(QString("select * from people where username = '%1'").arg(username)))
    {
        QMessageBox::information(0,"Notice","Success",QMessageBox::Close);
    }else
    {
        QMessageBox::critical(0,"Warning","ERROR!",QMessageBox::Close);
    }
}



/*---------------------------------------- ShowData ----------------------------------------*/
void myDatabase::ShowData()
{
    QSqlQuery query1;
    query1.exec(QString("select * from hotel"));                        //從數據庫選取整個hotel
    QSqlQuery query2;
    query2.exec(QString("select * from customer"));                        //從數據庫選取整個customer
    QSqlQuery query3;
    query3.exec(QString("select * from room"));
    QSqlQuery query4;
    query4.exec(QString("select * from myo"));
    QSqlQuery query5;
    query5.exec(QString("select * from num"));
    QString username;
    QString password;
    QString hotelname;
    QString roomtype;
    QString introduction;
    double price;
    unsigned int amount;
    QString image;
    QString id;
    int customerid;
    int orderid;
    QString roomid;
    QDate start;
    QDate end;
    QString status;



    //顯示hotel的數據
    qDebug() << "HOTEL";
    while(query1.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        username = query1.value(0).toString();                           //取出數據
        password = query1.value(1).toString();
        qDebug() << username << password;                               //顯示取出的數據
    }

    //顯示customer的數據
    qDebug() << "CUSTOMER";
    while(query2.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        username = query2.value(0).toString();                           //取出數據
        password = query2.value(1).toString();
        id       = query2.value(2).toInt();
        qDebug() << username << password;                               //顯示取出的數據
    }

    //顯示room的數據
    qDebug() << "ROOM";
    while(query3.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        hotelname       = query3.value(0).toString();                           //取出數據
        roomtype        = query3.value(1).toString();
        introduction    = query3.value(2).toString();
        price           = query3.value(3).toDouble();
        amount          = query3.value(4).toUInt();
        image           = query3.value(5).toString();
        id              = query3.value(6).toString();
        qDebug() << hotelname << roomtype << introduction << price << amount << image << id;                               //顯示取出的數據
    }

    qDebug() << "ORDER";
    while(query4.next())
    {
        orderid         = query4.value(0).toInt();
        customerid      = query4.value(1).toInt();
        roomid          = query4.value(2).toString();
        hotelname       = query4 .value(3).toString();
        roomtype        = query4 .value(4).toString();
        price           = query4.value(5).toDouble();
        start           = query4.value(6).toDate();
        end             = query4.value(7).toDate();
        status          = query4.value(8).toString();
        qDebug() << orderid << customerid << roomid << hotelname << roomtype << price
                 << start << end << status;
    }

    qDebug() << "NUMBER";
    query5.next();
    qDebug() << "CUSTOMER" << query5.value(0).toInt();
    qDebug() << "ROOM" << query5.value(1).toInt();
    qDebug() << "ORDER" << query5.value(2).toInt();
}



/*---------------------------------------- getHotel ----------------------------------------*/
void myDatabase::getHotel(QVector<hotel>&allHotel)
{
    QSqlQuery query;
    query.exec(QString("select * from hotel"));
    QString username;
    QString password;
    hotel* newhotel;

    while(query.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        username = query.value(0).toString();                           //取出數據
        password = query.value(1).toString();
        newhotel = new hotel;                                      //建立一個新的hotel_user對象
        newhotel->addData(username,password);
        allHotel.push_back(*newhotel);                                  //把newhotel從後面加入allHotel
    }
}


/*---------------------------------------- getCustomer ----------------------------------------*/
void myDatabase::getCustomer(QVector<customer>& allCustomer)
{
    QSqlQuery query;
    query.exec(QString("select * from customer"));
    QString username;
    QString password;
    int id;
    customer* newcustomer;

    while(query.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        username = query.value(0).toString();                           //取出數據
        password = query.value(1).toString();
        id = query.value(2).toInt();
        newcustomer = new customer(username, password, id);             //建立一個新的customer對象
        allCustomer.push_back(*newcustomer);                            //把newcustomer從後面加入allCustomer
    }
}


/*---------------------------------------- getCustomerNum ----------------------------------------*/
int myDatabase::getCustomerNum()
{
    QSqlQuery query;
    query.exec(QString("select * from num where idn = '%1'").arg(1));
    query.next();
    return query.value(0).toInt();
}




/*---------------------------------------- CreateHotelRoom ----------------------------------------*/
void myDatabase::CreateHotelRoom(QString setHotelName, QString setRoomType, QString setIntroduction,
                                 double setPrice, unsigned int setAmount, QString imageAddress, QString id)
{
    QSqlQuery query;
    if((!SearchRoomData(setHotelName, setRoomType)) && SearchHotelData(setHotelName))
    {
        query.exec(QString("insert into room(hotelname, roomtype, introduction, price, amount, image, id) values('%1','%2','%3','%4','%5','%6', '%7')")
                   .arg(setHotelName).arg(setRoomType).arg(setIntroduction).arg(setPrice).arg(setAmount).arg(imageAddress).arg(id));
        QMessageBox::information(0,"Notice","Create Room Success",QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(0,"Warning",setRoomType+" has existed, please input a new one.",QMessageBox::Ok);
    }
}



/*---------------------------------------- ChangeRoomData ----------------------------------------*/
void myDatabase::ChangeRoomData(QString newHotelName, QString newRoomType, QString newIntroduction,
                           double newPrice, unsigned int newAmount, QString newimage, QString newid)
{
    QSqlQuery query;
    query.exec(QString("update room set introduction = '%1', price = '%2', amount = '%3', image = '%4', id = '%5'"
                       "where hotelname = '%6' and roomtype = '%7'")
               .arg(newIntroduction).arg(newPrice).arg(newAmount).arg(newimage).arg(newid).arg(newHotelName).arg(newRoomType));
}

void myDatabase::ChangeRoomData(QString newHotelName, QString newRoomType, QString newIntroduction)
{
    QSqlQuery query;
    query.exec(QString("update room set introduction = '%1' where hotelname = '%2' and roomtype = '%3'")
               .arg(newIntroduction).arg(newHotelName).arg(newRoomType));
}

void myDatabase::ChangeRoomData(QString newHotelName, QString newRoomType, double newPrice)
{
    QSqlQuery query;
    query.exec(QString("update room set price = '%1' where hotelname = '%2' and roomtype = '%3'")
               .arg(newPrice).arg(newHotelName).arg(newRoomType));
}

void myDatabase::ChangeRoomData(QString newHotelName, QString newRoomType, unsigned int newAmount)
{
    QSqlQuery query;
    query.exec(QString("update room set amount = '%1' where hotelname = '%2' and roomtype = '%3'")
               .arg(newAmount).arg(newHotelName).arg(newRoomType));
}


/*---------------------------------------- UpdateOrderStatus ----------------------------------------*/
void myDatabase::UpdateOrderStatus(int orderid)
{
    QSqlQuery query;
    query.exec(QString("update myo set status = '%1' where oid = '%2'")
               .arg("expired").arg(orderid));
}




/*---------------------------------------- ChangeOrderStatus ----------------------------------------*/
void myDatabase::ChangeOrderStatus(int orderid, QString newstatus)
{
    QSqlQuery query;
    query.exec(QString("update myo set status = '%1' where oid = '%2'").arg(newstatus).arg(orderid));
}


/*---------------------------------------- ChangeCustomerPW ----------------------------------------*/
void myDatabase::ChangeCustomerPW(QString username, QString newpassword)
{
    QSqlQuery query;
    query.exec(QString("update customer set password_c = '%1' where username_c = '%2'").arg(newpassword).arg(username));
}



/*---------------------------------------- getRoom ----------------------------------------*/
//room(hotelname varchar(8), roomtype varchar(20), introduction varchar(150), price double, amount unsigned int)
void myDatabase::getRoom(QVector<hotelroom>& allRoom)
{
    QSqlQuery query;
    query.exec(QString("select * from room"));
    QString hotelname;
    QString roomtype;
    QString introduction;
    double price;
    unsigned int amount;
    QString image;
    QString id;
    hotelroom* newhotelroom;

    while(query.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        hotelname = query.value(0).toString();                           //取出數據
        roomtype = query.value(1).toString();
        introduction = query.value(2).toString();
        price = query.value(3).toDouble();
        amount = query.value(4).toUInt();
        image = query.value(5).toString();
        id = query.value(6).toString();
        newhotelroom = new hotelroom;                                      //建立一個新的hotel_user對象
        newhotelroom->addRoomData(hotelname, roomtype, introduction, price, amount, image, id);
        allRoom.push_back(*newhotelroom);                               //把newhotel從後面加入allHotel
    }
}


void myDatabase::getRoom(QVector<hotelroom> &Room, QString findHotelName)
{
    QSqlQuery query;
    query.exec(QString("select * from room where hotelname = '%1'").arg(findHotelName));
    QString hotelname;
    QString roomtype;
    QString introduction;
    double price;
    unsigned int amount;
    QString image;
    QString id;
    hotelroom* newhotelroom;

    while(query.next())                                                 //讓query指向下一條,直到數據庫結尾結束while
    {
        hotelname = query.value(0).toString();                           //取出數據
        roomtype = query.value(1).toString();
        introduction = query.value(2).toString();
        price = query.value(3).toDouble();
        amount = query.value(4).toUInt();
        image = query.value(5).toString();
        id = query.value(6).toString();
        newhotelroom = new hotelroom;                                      //建立一個新的hotel_user對象
        newhotelroom->addRoomData(hotelname, roomtype, introduction, price, amount, image, id);
        Room.push_back(*newhotelroom);                               //把newhotel從後面加入allHotel
    }
}



/*---------------------------------------- getOrder ----------------------------------------*/
//order(orderid int, customerid int, roomid varchar(2), startdate varchar(10), enddate varchar(10), status varchar(8)
void myDatabase::getOrder(QVector<order> &allOrder)
{
    QSqlQuery query;
    query.exec(QString("select * from myo"));
    int id_o;
    int id_c;
    QString id_r;
    QString hotelname;
    QString roomtype;
    double price;
    QDate start;
    QDate end;
    QString status;
    order *neworder;

    while(query.next())
    {
        id_o = query.value(0).toInt();
        id_c = query.value(1).toInt();
        id_r = query.value(2).toString();
        hotelname = query.value(3).toString();
        roomtype = query.value(4).toString();
        price = query.value(5).toDouble();
        start = QDate::fromString(query.value(6).toString(), "yyyy-MM-dd");
        end =   QDate::fromString(query.value(7).toString(), "yyyy-MM-dd");
        status = query.value(8).toString();
        neworder = new order(id_o, id_c, id_r, hotelname, roomtype, price, start, end, status);
        allOrder.push_back(*neworder);

    }
}

void myDatabase::getOrder(QVector<order> &Order, QString findHotelName)
{
    QSqlQuery query;
    query.exec(QString("select * from myo where hotelname_o = '%1'").arg(findHotelName));
    int id_o;
    int id_c;
    QString id_r;
    QString hotelname;
    QString roomtype;
    double price;
    QDate start;
    QDate end;
    QString status;
    order *neworder;

    while(query.next())
    {
        id_o = query.value(0).toInt();
        id_c = query.value(1).toInt();
        id_r = query.value(2).toString();
        hotelname = query.value(3).toString();
        roomtype = query.value(4).toString();
        price = query.value(5).toDouble();
        start = query.value(6).toDate();
        end =  query.value(7).toDate();
        status = query.value(8).toString();
        neworder = new order(id_o, id_c, id_r, hotelname, roomtype, price, start, end, status);
        Order.push_back(*neworder);
    }
}

/*---------------------------------------- getOrderNum ----------------------------------------*/
int myDatabase::getOrderNum()
{
    QSqlQuery query;
    query.exec(QString("select * from num"));
    query.next();
    return query.value(2).toInt();
}

