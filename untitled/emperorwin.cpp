#include "emperorwin.h"
#include "ui_emperorwin.h"
#include "ui_parisianwin.h"
#include "alldata.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDate>
#include <QDebug>


emperorwin::emperorwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emperorwin)
{
    ui->setupUi(this);
    hotelroom roomdata;

/*------------------------------------- DeluxeRoom -------------------------------------*/
    allData::getRoomData(roomdata, "Emperor", "DeluxeRoom");
    ui->introduction1->setText(roomdata.getIntroduction());
    ui->price1->setValue(roomdata.getPrice());
    ui->number1->setValue(roomdata.getAmount());
    allData::getOrder(room1order, "E1");
    getroom1wid();
    for(int i=0; i<room1wig.size(); i++)
    {
        ui->showorder->addWidget(room1wig[i]);
    }


/*------------------------------------- FamilySuite -------------------------------------*/
    allData::getRoomData(roomdata, "Emperor", "FamilySuite");
    ui->introduction2->setText(roomdata.getIntroduction());
    ui->price2->setValue(roomdata.getPrice());
    ui->number2->setValue(roomdata.getAmount());
    allData::getOrder(room2order, "E2");
    getroom2wid();
    for(int i=0; i<room2wig.size(); i++)
    {
        ui->showorder_2->addWidget(room2wig[i]);
    }


/*------------------------------------- DeluxeQueenSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Emperor", "DeluxeQueenSuite");
    ui->introduction3->setText(roomdata.getIntroduction());
    ui->price3->setValue(roomdata.getPrice());
    ui->number3->setValue(roomdata.getAmount());
    allData::getOrder(room1order, "E3");
    getroom3wid();
    for(int i=0; i<room3wig.size(); i++)
    {
        ui->showorder_3->addWidget(room3wig[i]);
    }


/*------------------------------------- ExecutiveDoubleRoom -------------------------------------*/
    allData::getRoomData(roomdata, "Emperor", "ExecutiveDoubleRoom");
    ui->introduction4->setText(roomdata.getIntroduction());
    ui->price4->setValue(roomdata.getPrice());
    ui->number4->setValue(roomdata.getAmount());
    allData::getOrder(room4order, "E4");
    getroom4wid();
    for(int i=0; i<room4wig.size(); i++)
    {
        ui->showorder_4->addWidget(room4wig[i]);
    }
}

emperorwin::~emperorwin()
{
    delete ui;
}

void emperorwin::getroom1wid()
{
    for(int i=0; i<room1order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room1order[i].getOrderID());
        room1wig.push_back(newWid);
    }
}

void emperorwin::getroom2wid()
{
    for(int i=0; i<room2order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room2order[i].getOrderID());
        room2wig.push_back(newWid);
    }
}

void emperorwin::getroom3wid()
{
    for(int i=0; i<room3order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room3order[i].getOrderID());
        room3wig.push_back(newWid);
    }
}

void emperorwin::getroom4wid()
{
    for(int i=0; i<room4order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room4order[i].getOrderID());
        room4wig.push_back(newWid);
    }
}


void emperorwin::on_saveintroduction1_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeRoom", ui->introduction1->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_saveintroduction2_clicked()
{
    allData::changeRoomData("Emperor", "FamilySuite", ui->introduction2->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_saveitroduction3_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeQueenSuite", ui->introduction3->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_saveintroduction4_clicked()
{
    allData::changeRoomData("Emperor", "ExecutiveDoubleRoom", ui->introduction4->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setprice1_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeRoom", ui->price1->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setprice2_clicked()
{
    allData::changeRoomData("Emperor", "FamilySuite", ui->price2->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setprice3_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeQueenSuite", ui->price3->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setprice4_clicked()
{
    allData::changeRoomData("Emperor", "ExecutiveDoubleRoom", ui->price4->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setroom1_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeRoom", (unsigned int)(ui->number1->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setnumber2_clicked()
{
    allData::changeRoomData("Emperor", "FamilySuite", (unsigned int)(ui->number2->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setnumber3_clicked()
{
    allData::changeRoomData("Emperor", "DeluxeQueenSuite", (unsigned int)(ui->number3->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_setnumber4_clicked()
{
    allData::changeRoomData("Emperor", "ExecutiveDoubleRoom", (unsigned int)(ui->number4->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void emperorwin::on_checkorder1_clicked()
{
    QDate date = ui->calendarWidget_1->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Emperor", "DeluxeRoom");
    int Order = allData::getRoomOrderNum("E1", date);
    ui->order1->setText(QString("%1").arg(Order));
}

void emperorwin::on_checkorder2_clicked()
{
    QDate date = ui->calendarWidget_7->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Emperor", "FamilySuite");
    int Order = allData::getRoomOrderNum("E2", date);
    ui->order2->setText(QString("%1").arg(Order));
}

void emperorwin::on_checkorder3_clicked()
{
    QDate date = ui->calendarWidget_8->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Emperor", "DeluxeQueenSuite");
    int Order = allData::getRoomOrderNum("E3", date);
    ui->order3->setText(QString("%1").arg(Order));
}

void emperorwin::on_checkorder4_clicked()
{
    QDate date = ui->calendarWidget_9->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Emperor", "ExecutiveDoubleRoom");
    int Order = allData::getRoomOrderNum("E4", date);
    ui->order4->setText(QString("%1").arg(Order));
}

void emperorwin::on_logout_clicked()
{
    this->close();
}
