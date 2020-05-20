#include "roomforcustomer.h"
#include "ui_roomforcustomer.h"
#include "bookroomwin.h"

#include <QDebug>

roomforcustomer::roomforcustomer(QWidget *parent, QString newHotelName, QString newRoomType,
                                 QString newRoomIntroduction, double newRoomPrice, unsigned int newRoomAmount,
                                 QString newImageAddress, QString newroomid, int newcustomerid) :
    QWidget(parent), ui(new Ui::roomforcustomer), HotelName(newHotelName), RoomType(newRoomType),
    RoomIntroduction(newRoomIntroduction), RoomPrice(newRoomPrice), RoomAmount(newRoomAmount),
    ImageAddress(newImageAddress), RoomID(newroomid), CustomerID(newcustomerid)
{
    ui->setupUi(this);
    ui->Label_image->setPixmap(ImageAddress);
    ui->Label_price->setText(QString("%1").arg(RoomPrice));
    ui->introduction->setText(RoomIntroduction);
    ui->introduction->setStyleSheet("background-color:rgb(255,255,255)");
}

roomforcustomer::~roomforcustomer()
{
    delete ui;
}

void roomforcustomer::setAll(QString newHotelName, QString newRoomType, QString newRoomIntroduction, double newRoomPrice,
                             unsigned int newRoomAmount, QString newImageAddress, QString newroomid, int newcustomerid)
{
    HotelName = newHotelName;
    RoomType = newRoomType;
    RoomIntroduction = newRoomIntroduction;
    RoomPrice = newRoomPrice;
    RoomAmount = newRoomAmount;
    ImageAddress = newImageAddress;
    RoomID = newroomid;
    CustomerID = newcustomerid;
}

void roomforcustomer::on_pushButton_clicked()
{
    bookroomwin *win = new bookroomwin(0, HotelName, RoomType, RoomPrice, RoomAmount, RoomID, CustomerID);
    win->show();
}

void roomforcustomer::on_commandLinkButton_clicked()
{

}
