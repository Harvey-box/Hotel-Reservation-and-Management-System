#include "roomforadmin.h"
#include "ui_roomforadmin.h"

roomforadmin::roomforadmin(QWidget *parent, QString newHotelName, QString newRoomType,
                           QString newRoomIntroduction, double newRoomPrice, unsigned int newRoomAmount,
                           QString newImageAddress, QString newroomid) :
QWidget(parent),  HotelName(newHotelName), RoomType(newRoomType),
RoomIntroduction(newRoomIntroduction), RoomPrice(newRoomPrice), RoomAmount(newRoomAmount),
ImageAddress(newImageAddress), RoomID(newroomid),
    ui(new Ui::roomforadmin)
{
    ui->setupUi(this);
    ui->Label_image->setPixmap(ImageAddress);
    ui->Label_price_2->setText(QString("%1").arg(RoomPrice));
    ui->introduction_2->setText(RoomIntroduction);
    ui->introduction_2->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_amount->setText(QString("%1").arg(RoomAmount));
    ui->label_hotel->setText(HotelName);
}

roomforadmin::~roomforadmin()
{
    delete ui;
}
