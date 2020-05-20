#include "venetianwin.h"
#include "ui_venetianwin.h"
#include "alldata.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDate>
#include <QDebug>


venetianwin::venetianwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::venetianwin)
{
    ui->setupUi(this);
    hotelroom roomdata;

/*------------------------------------- RoyaleDeluxeSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Venetian", "RoyaleDeluxeSuite");
    ui->introduction1_5->setText(roomdata.getIntroduction());
    ui->price1_5->setValue(roomdata.getPrice());
    ui->number1_5->setValue(roomdata.getAmount());
    allData::getOrder(room1order, "V1");
    getroom1wid();
    for(int i=0; i<room1wig.size(); i++)
    {
        ui->showorder->addWidget(room1wig[i]);
    }


/*------------------------------------- PremioBellaSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Venetian", "PremioBellaSuite");
    ui->introduction2_5->setText(roomdata.getIntroduction());
    ui->price2_5->setValue(roomdata.getPrice());
    ui->number2_5->setValue(roomdata.getAmount());
    allData::getOrder(room2order, "V2");
    getroom1wid();
    for(int i=0; i<room2wig.size(); i++)
    {
        ui->showorder_2->addWidget(room2wig[i]);
    }


/*------------------------------------- PremioRoyaleSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Venetian", "PremioRoyaleSuite");
    ui->introduction3_5->setText(roomdata.getIntroduction());
    ui->price3_5->setValue(roomdata.getPrice());
    ui->number3_5->setValue(roomdata.getAmount());
    allData::getOrder(room3order, "V3");
    getroom3wid();
    for(int i=0; i<room3wig.size(); i++)
    {
        ui->showorder_3->addWidget(room3wig[i]);
    }


/*------------------------------------- BellaDeluxeSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Venetian", "BellaDeluxeSuite");
    ui->introduction4_5->setText(roomdata.getIntroduction());
    ui->price4_5->setValue(roomdata.getPrice());
    ui->number4_5->setValue(roomdata.getAmount());
    allData::getOrder(room4order, "V4");
    getroom4wid();
    for(int i=0; i<room4wig.size(); i++)
    {
        ui->showorder_4->addWidget(room4wig[i]);
    }


/*------------------------------------- FamigliaSuite -------------------------------------*/
    allData::getRoomData(roomdata, "Venetian", "LyonSuite");
    ui->introduction4_5->setText(roomdata.getIntroduction());
    ui->price4_5->setValue(roomdata.getPrice());
    ui->number4_5->setValue(roomdata.getAmount());
    allData::getOrder(room5order, "V5");
    getroom5wid();
    for(int i=0; i<room5wig.size(); i++)
    {
        ui->showorder_5->addWidget(room5wig[i]);
    }
}

venetianwin::~venetianwin()
{
    delete ui;
}

void venetianwin::getroom1wid()
{
    for(int i=0; i<room1order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room1order[i].getOrderID());
        room1wig.push_back(newWid);
    }
}

void venetianwin::getroom2wid()
{
    for(int i=0; i<room2order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room2order[i].getOrderID());
        room2wig.push_back(newWid);
    }
}

void venetianwin::getroom3wid()
{
    for(int i=0; i<room3order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room3order[i].getOrderID());
        room3wig.push_back(newWid);
    }
}

void venetianwin::getroom4wid()
{
    for(int i=0; i<room4order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room4order[i].getOrderID());
        room4wig.push_back(newWid);
    }
}

void venetianwin::getroom5wid()
{
    for(int i=0; i<room5order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room5order[i].getOrderID());
        room5wig.push_back(newWid);
    }
}


void venetianwin::on_saveintroduction1_5_clicked()
{
    allData::changeRoomData("Venetian", "RoyaleDeluxeSuite", ui->introduction1_5->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_saveintroduction2_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioBellaSuite", ui->introduction2_5->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_saveitroduction3_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioRoyaleSuite", ui->introduction3_5->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_saveintroduction4_5_clicked()
{
    allData::changeRoomData("Venetian", "BellaDeluxeSuite", ui->introduction4_5->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_saveintroduction4_6_clicked()
{
    allData::changeRoomData("Venetian", "FamigliaSuite", ui->introduction4_5->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setprice1_5_clicked()
{
    allData::changeRoomData("Venetian", "RoyaleDeluxeSuite", ui->price1_5->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setprice2_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioBellaSuite", ui->price2_5->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setprice3_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioRoyaleSuite", ui->price3_5->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setprice4_5_clicked()
{
    allData::changeRoomData("Venetian", "BellaDeluxeSuite", ui->price4_5->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setprice4_6_clicked()
{
    allData::changeRoomData("Venetian", "FamigliaSuite", ui->price4_5->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setroom1_5_clicked()
{
    allData::changeRoomData("Venetian", "RoyaleDeluxeSuite", (unsigned int)(ui->number1_5->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setnumber2_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioBellaSuite", (unsigned int)(ui->number2_5->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setnumber3_5_clicked()
{
    allData::changeRoomData("Venetian", "PremioRoyaleSuite", (unsigned int)(ui->number3_5->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setnumber4_5_clicked()
{
    allData::changeRoomData("Venetian", "BellaDeluxeSuite", (unsigned int)(ui->number4_5->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_setnumber4_6_clicked()
{
    allData::changeRoomData("Venetian", "FamigliaSuite", (unsigned int)(ui->number4_5->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void venetianwin::on_checkorder1_5_clicked()
{
    QDate date = ui->calendarWidget1_5->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Venetian", "RoyaleDeluxeSuite");
    int Order = allData::getRoomOrderNum("V1", date);
    ui->order1_5->setText(QString("%1").arg(Order));
}

void venetianwin::on_checkorder2_5_clicked()
{
    QDate date = ui->calendarWidget2_5->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Venetian", "PremioBellaSuite");
    int Order =  allData::getRoomOrderNum("V2", date);
    ui->order2_5->setText(QString("%1").arg(Order));
}

void venetianwin::on_checkorder3_5_clicked()
{
    QDate date = ui->calendarWidget3_5->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Venetian", "PremioRoyaleSuite");
    int Order = allData::getRoomOrderNum("V3", date);
    ui->order3_5->setText(QString("%1").arg(Order));
}

void venetianwin::on_checkorder4_5_clicked()
{
    QDate date = ui->calendarWidget4_5->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Venetian", "BellaDeluxeSuite");
    int Order = allData::getRoomOrderNum("V4", date);
    ui->order4_5->setText(QString("%1").arg(Order));
}

void venetianwin::on_checkorder4_6_clicked()
{
    QDate date = ui->calendarWidget4_6->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Venetian", "FamigliaSuite");
    int Order = allData::getRoomOrderNum("V4", date);
    ui->order4_6->setText(QString("%1").arg(Order));
}

void venetianwin::on_logout_5_clicked()
{
    this->close();
}
