#include "bookroomwin.h"
#include "ui_bookroomwin.h"
#include "alldata.h"

#include <QDate>
#include <QMessageBox>
#include <QDebug>

bookroomwin::bookroomwin(QWidget *parent, QString newHotelName, QString newRoomType, double newRoomPrice,
                         unsigned int newRoomAmount, QString newRoomID, int newCustomerID) :
    QWidget(parent), HotelName(newHotelName), RoomType(newRoomType), RoomPrice(newRoomPrice),
    RoomAmount(newRoomAmount), RoomID(newRoomID), CustomerID(newCustomerID),
    ui(new Ui::bookroomwin)
{
    ui->setupUi(this);
    this->setFixedSize(650,360);

    ui->label_start->setText("(Check in date)");
}

bookroomwin::~bookroomwin()
{
    delete ui;
}

void bookroomwin::on_calendarWidget_clicked(const QDate &date)
{
    Available = RoomAmount - allData::getRoomOrderNum(RoomID, ui->calendarWidget->selectedDate());
    ui->label_available->setText(QString("%1").arg(Available));
}

void bookroomwin::on_pushButton_clicked()
{
    enddate = ui->calendarWidget_2->selectedDate();
    if(startdate.isNull() || enddate.isNull())
    {
        QMessageBox::critical(0,"WARNING","Please select your date", QMessageBox::Close);
    }else if(startdate >= enddate)
    {
        QMessageBox::critical(0,"WARNING","Please confirm your date", QMessageBox::Close);
    }else
    {
        int num=1;
        while(startdate.addDays(num) < enddate)
        {
            num++;
        }
        total = num*RoomPrice;
        allData::addOrder(CustomerID, RoomID, HotelName, RoomType, total, startdate, enddate);
        this->close();
    }

}

void bookroomwin::on_pushButton_2_clicked()
{
    startdate = ui->calendarWidget->selectedDate();
    ui->label_start->setText(startdate.toString());
    qDebug() << startdate.toString("yyyy-MM-dd");
}
