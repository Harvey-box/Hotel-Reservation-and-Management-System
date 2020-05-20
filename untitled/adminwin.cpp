#include "adminwin.h"
#include "ui_adminwin.h"
#include "alldata.h"

adminwin::adminwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminwin)
{
    ui->setupUi(this);
    allRoomData = *(allData::getallRoom());
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->room->addWidget(allRoomWid[i]);
    }


    this->setFixedSize(1000,650);
    myallorder = *(allData::getallOrder());
    getmyOrderWin();

    for(int i=0; i<myorderwin.size(); i++)
    {
        ui->order->addWidget(myorderwin[i]);
    }
}

adminwin::~adminwin()
{
    delete ui;
}

void adminwin::getRoomWid()
{
    for(int i=0; i<allRoomData.size(); i++)
    {
       roomforadmin* newWid;
       newWid = new roomforadmin(0, allRoomData[i].getHotelName(), allRoomData[i].getRoomType(),
                                    allRoomData[i].getIntroduction(), allRoomData[i].getPrice(),
                                    allRoomData[i].getAmount(), allRoomData[i].getimage(),
                                    allRoomData[i].getid());
       allRoomWid.push_back(newWid);
    }
}

void adminwin::getmyOrderWin()
{
    for(int i=0; i<myallorder.size(); i++)
    {
        usercheckorderwidget* newWid;
        newWid = new usercheckorderwidget(myallorder[i].getOrderID());
        myorderwin.push_back(newWid);
    }
}
