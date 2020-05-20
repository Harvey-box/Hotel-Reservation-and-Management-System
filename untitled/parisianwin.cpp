#include "parisianwin.h".h"
#include "ui_parisianwin.h"
#include "alldata.h"
#include "hotelcheckorderwidget.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

parisianwin::parisianwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parisianwin)
{
    ui->setupUi(this);
    hotelroom roomdata;

/*------------------------------------- EiffelTowerRoom -------------------------------------*/
    allData::getRoomData(roomdata, "Parisian", "EiffelTowerRoom");
    ui->introduction1->setText(roomdata.getIntroduction());
    ui->price1->setValue(roomdata.getPrice());
    ui->number1->setValue(roomdata.getAmount());
    qDebug() << roomdata.getPrice() << roomdata.getAmount();
    allData::getOrder(room1order, "P1");
    getroom1wid();
    for(int i=0; i<room1wig.size(); i++)
    {
        ui->showorder->addWidget(room1wig[i]);
    }


/*------------------------------------- DeluxeRoom -------------------------------------*/
    allData::getRoomData(roomdata, "Parisian", "DeluxeRoom");
    ui->introduction2->setText(roomdata.getIntroduction());
    ui->price2->setValue(roomdata.getPrice());
    ui->number2->setValue(roomdata.getAmount());
    allData::getOrder(room2order, "P2");
    getroom2wid();
    for(int i=0; i<room2wig.size(); i++)
    {
        ui->showorder_2->addWidget(room2wig[i]);
    }


/*------------------------------------- FamilleRoom -------------------------------------*/
    allData::getRoomData(roomdata, "Parisian", "FamilleRoom");
    ui->introduction3->setText(roomdata.getIntroduction());
    ui->price3->setValue(roomdata.getPrice());
    ui->number3->setValue(roomdata.getAmount());
    allData::getOrder(room3order, "P3");
    getroom3wid();
    for(int i=0; i<room3wig.size(); i++)
    {
        ui->showorder_3->addWidget(room3wig[i]);
    }


/*------------------------------------- LyonSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Parisian", "LyonSuite");
    ui->introduction4->setText(roomdata.getIntroduction());
    ui->price4->setValue(roomdata.getPrice());
    ui->number4->setValue(roomdata.getAmount());
    allData::getOrder(room4order, "P4");
    getroom4wid();
    for(int i=0; i<room4wig.size(); i++)
    {
        ui->showorder_4->addWidget(room4wig[i]);
    }
}

parisianwin::~parisianwin()
{
    delete ui;
}

void parisianwin::getroom1wid()
{
    for(int i=0; i<room1order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room1order[i].getOrderID());
        room1wig.push_back(newWid);
    }
}

void parisianwin::getroom2wid()
{
    for(int i=0; i<room2order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room2order[i].getOrderID());
        room2wig.push_back(newWid);
    }
}

void parisianwin::getroom3wid()
{
    for(int i=0; i<room3order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room3order[i].getOrderID());
        room3wig.push_back(newWid);
    }
}

void parisianwin::getroom4wid()
{
    for(int i=0; i<room4order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room4order[i].getOrderID());
        room4wig.push_back(newWid);
    }
}


void parisianwin::on_saveintroduction1_clicked()
{
    allData::changeRoomData("Parisian", "EiffelTowerRoom", ui->introduction1->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_saveintroduction2_clicked()
{
    allData::changeRoomData("Parisian", "DeluxeRoom", ui->introduction2->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_saveitroduction3_clicked()
{
    allData::changeRoomData("Parisian", "FamilleRoom", ui->introduction3->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_saveintroduction4_clicked()
{
    allData::changeRoomData("Parisian", "LyonSuite", ui->introduction4->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setprice1_clicked()
{
    allData::changeRoomData("Parisian", "EiffelTowerRoom", ui->price1->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setprice2_clicked()
{
    allData::changeRoomData("Parisian", "DeluxeRoom", ui->price2->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setprice3_clicked()
{
    allData::changeRoomData("Parisian", "FamilleRoom", ui->price3->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setprice4_clicked()
{
    allData::changeRoomData("Parisian", "LyonSuite", ui->price4->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setroom1_clicked()
{
    allData::changeRoomData("Parisian", "EiffelTowerRoom", (unsigned int)(ui->number1->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setnumber2_clicked()
{
    allData::changeRoomData("Parisian", "DeluxeRoom", (unsigned int)(ui->number2->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setnumber3_clicked()
{
    allData::changeRoomData("Parisian", "FamilleRoom", (unsigned int)(ui->number3->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_setnumber4_clicked()
{
    allData::changeRoomData("Parisian", "LyonSuite", (unsigned int)(ui->number4->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void parisianwin::on_checkorder1_clicked()
{
    QDate date = ui->calendarWidget_1->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Parisian", "EiffelTowerRoom");
    int Order = allData::getRoomOrderNum("P1", date);
    ui->order1->setText(QString("%1").arg(Order));
}

void parisianwin::on_checkorder2_clicked()
{
    QDate date = ui->calendarWidget_7->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Parisian", "PremierLakeView");
    int Order = allData::getRoomOrderNum("P2", date);
    ui->order2->setText(QString("%1").arg(Order));
}

void parisianwin::on_checkorder3_clicked()
{
    QDate date = ui->calendarWidget_8->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Parisian", "FamilleRoom");
    int Order = allData::getRoomOrderNum("P3", date);
    ui->order3->setText(QString("%1").arg(Order));
}

void parisianwin::on_checkorder4_clicked()
{
    QDate date = ui->calendarWidget_9->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Parisian", "LyonSuite");
    int Order = allData::getRoomOrderNum("P4", date);
    ui->order4->setText(QString("%1").arg(Order));
}

void parisianwin::on_logout_clicked()
{
    this->close();
}
