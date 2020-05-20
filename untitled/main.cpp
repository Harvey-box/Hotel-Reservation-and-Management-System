#include "mainwindow.h"
#include "mydatabase.h"
#include "lisboawin.h"
#include "hoteldata.h"
#include "alldata.h"
#include "customerwin.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSplashScreen>
#include <Qt>
#include <QVector>
#include <QDebug>
#include <QDate>
#include <QMessageBox>


void datareset()
{
    myDatabase::CreateAdministrator();              //創建管理員帳戶
    myDatabase::CreateHotel("Lisboa", "lisboa");   //創建酒店帳戶
    myDatabase::CreateHotel("Parisian","parisian");
    myDatabase::CreateHotel("Venetian","venetian");
    myDatabase::CreateHotel("Emperor","emperor");

    myDatabase::CreateHotelRoom("Lisboa","Superior","",1688,100,"://images/lisboa/l_room1.jpg","L1");
    myDatabase::CreateHotelRoom("Lisboa","Deluxe","",1788,90,"://images/lisboa/l_room2.jpg","L2");
    myDatabase::CreateHotelRoom("Lisboa","SuperiorLakeView","",1888,60,"://images/lisboa/l_room3.jpg","L3");
    myDatabase::CreateHotelRoom("Lisboa","Corner","",16988,40,"://images/lisboa/l_room4.JPG","L4");
    myDatabase::CreateHotelRoom("Lisboa","PremierDeluxe","",2088,20,"://images/lisboa/l_room5.jpg","L5");
    myDatabase::CreateHotelRoom("Lisboa","PremierLakeView","",3088,10,"://images/lisboa/l_room6.jpg","L6");

    myDatabase::CreateHotelRoom("Parisian","EiffelTowerRoom","",1123.5,50,"://images/parisian/p_room1","P1");
    myDatabase::CreateHotelRoom("Parisian","DeluxeRoom","",973.5,100,"://images/parisian/p_room2.jpg","P2");
    myDatabase::CreateHotelRoom("Parisian","FamilleRoom","",1273.5,40,"://images/parisian/p_room3.jpg","P3");
    myDatabase::CreateHotelRoom("Parisian","LyonSuite","",1536,20,"://images/parisian/p_room4.jpg","P4");

    myDatabase::CreateHotelRoom("Venetian","RoyaleDeluxeSuite","",1443.3,100,"://images/venetian/v_room1","V1");
    myDatabase::CreateHotelRoom("Venetian","PremioBellaSuite","",1655.8,50,"://images/venetian/v_room2.jpg","V2");
    myDatabase::CreateHotelRoom("Venetian","PremioRoyaleSuite","",1570.8,60,"://images/venetian/v_room3.jpg","V3");
    myDatabase::CreateHotelRoom("Venetian","BellaDeluxeSuite","",1825.8,30,"://images/venetian/v_room4.jpg","V4");
    myDatabase::CreateHotelRoom("Venetian","FamigliaSuite","",2165.8,20,"://images/venetian/v_room5.jpg","V5");

    myDatabase::CreateHotelRoom("Emperor","DeluxeRoom","",918,100,"://images/emperor/e_room1","E1");
    myDatabase::CreateHotelRoom("Emperor","FamilySuite","",886,80,"://images/emperor/e_room2.jpg","E2");
    myDatabase::CreateHotelRoom("Emperor","DeluxeQueenSuite","",1373,50,"://images/emperor/e_room4.jpg","E3");
    myDatabase::CreateHotelRoom("Emperor","ExecutiveDoubleRoom","",1236,60,"://images/emperor/e_room5.jpg","E4");

    myDatabase::setNumber();
    myDatabase::ShowData();                         //查看數據庫內資料
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myDatabase::ConnectDatabase();                  //連接數據庫
//    datareset();
    myDatabase::ShowData();

    allData::setallHotel();
    allData::setallCustomer();
    allData::setallRoom();
    allData::setLisboaRoom();
    allData::setParisianRoom();
    allData::setVenetianRoom();
    allData::setEmperorRoom();
    allData::setallOrder();
    allData::updateOrderStatus();
    customer::CusNumber = myDatabase::getCustomerNum();
    order::ordernum = myDatabase::getOrderNum();
    allData::showdata();


//    QVector<hotelroom> allRoom;
//    myDatabase::getRoom(allRoom);
/*    for(int i=0; i<lisboaroom.size(); i++)
    {
        qDebug() << lisboaroom[i].getHotelName() << lisboaroom[i].getRoomType()
                 << lisboaroom[i].getIntroduction() << lisboaroom[i].getPrice() << lisboaroom[i].getAmount();
    }*/






 //   QVector<hotelroom> allRoom;
 //   myDatabase::getRoomData(allRoom);

    MainWindow win;                     //定義主窗口(登入界面)
    win.show();


    return a.exec();
}
