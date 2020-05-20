#include "lisboawin.h"
#include "ui_lisboawin.h"
#include "alldata.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

lisboawin::lisboawin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lisboawin)
{
    ui->setupUi(this);
    hotelroom roomdata;

/*------------------------------------- Superior -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "Superior");
    ui->Lintroduction_Superior->setText(roomdata.getIntroduction());
    ui->Lprice_Superior->setValue(roomdata.getPrice());
    ui->Lamout_Superior->setValue(roomdata.getAmount());
    allData::getOrder(room1order, "L1");
    getroom1wid();
    for(int i=0; i<room1wig.size(); i++)
    {
        ui->showorder->addWidget(room1wig[i]);
    }


/*------------------------------------- Deluxe -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "Deluxe");
    ui->Lintroduction_Deluxe->setText(roomdata.getIntroduction());
    ui->Lprice_Deluxe->setValue(roomdata.getPrice());
    ui->Lamout_Deluxe->setValue(roomdata.getAmount());
    allData::getOrder(room2order, "L2");
    getroom1wid();
    for(int i=0; i<room2wig.size(); i++)
    {
        ui->showorder_2->addWidget(room2wig[i]);
    }


/*------------------------------------- SuperiorLakeView -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "SuperiorLakeView");
    ui->Lintroduction_SuperiorLakeView->setText(roomdata.getIntroduction());
    ui->Lprice_SuperiorLakeView->setValue(roomdata.getPrice());
    ui->Lamout_SuperiorLakeView->setValue(roomdata.getAmount());
    allData::getOrder(room1order, "L3");
    getroom3wid();
    for(int i=0; i<room3wig.size(); i++)
    {
        ui->showorder_3->addWidget(room3wig[i]);
    }


/*------------------------------------- Corner -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "Corner");
    ui->Lintroduction_Corner->setText(roomdata.getIntroduction());
    ui->Lprice_Corner->setValue(roomdata.getPrice());
    ui->Lamout_Corner->setValue(roomdata.getAmount());
    allData::getOrder(room4order, "L4");
    getroom4wid();
    for(int i=0; i<room4wig.size(); i++)
    {
        ui->showorder_4->addWidget(room4wig[i]);
    }


/*------------------------------------- PremierDeluxe -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "PremierDeluxe");
    ui->Lintroduction_PremierDeluxe->setText(roomdata.getIntroduction());
    ui->Lprice_PremierDeluxe->setValue(roomdata.getPrice());
    ui->Lamout_PremierDeluxe->setValue(roomdata.getAmount());
    allData::getOrder(room5order, "L5");
    getroom5wid();
    for(int i=0; i<room5wig.size(); i++)
    {
        ui->showorder_5->addWidget(room5wig[i]);
    }


/*------------------------------------- PremierLakeView -------------------------------------*/
    allData::getRoomData(roomdata, "Lisboa", "PremierLakeView");
    ui->Lintroduction_PremierLakeView->setText(roomdata.getIntroduction());
    ui->Lprice_PremierLakeView->setValue(roomdata.getPrice());
    ui->Lamout_PremierLakeView->setValue(roomdata.getAmount());
    allData::getOrder(room6order, "L6");
    getroom6wid();
    for(int i=0; i<room6wig.size(); i++)
    {
        ui->showorder_6->addWidget(room6wig[i]);
    }
}

lisboawin::~lisboawin()
{
    delete ui;
}

void lisboawin::getroom1wid()
{
    for(int i=0; i<room1order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room1order[i].getOrderID());
        room1wig.push_back(newWid);
    }
}

void lisboawin::getroom2wid()
{
    for(int i=0; i<room2order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room2order[i].getOrderID());
        room2wig.push_back(newWid);
    }
}

void lisboawin::getroom3wid()
{
    for(int i=0; i<room3order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room3order[i].getOrderID());
        room3wig.push_back(newWid);
    }
}

void lisboawin::getroom4wid()
{
    for(int i=0; i<room4order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room4order[i].getOrderID());
        room4wig.push_back(newWid);
    }
}

void lisboawin::getroom5wid()
{
    for(int i=0; i<room5order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room5order[i].getOrderID());
        room5wig.push_back(newWid);
    }
}

void lisboawin::getroom6wid()
{
    for(int i=0; i<room6order.size(); i++)
    {
        hotelcheckorderwidget* newWid;
        newWid = new hotelcheckorderwidget(room6order[i].getOrderID());
        room6wig.push_back(newWid);
    }
}


/*----------------------------------------------------------- slots -----------------------------------------------------------*/
void lisboawin::on_Lsaveintroduction_Superior_clicked()
{
    allData::changeRoomData("Lisboa", "Superior", ui->Lintroduction_Superior->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_Superior_clicked()
{
    allData::changeRoomData("Lisboa", "Superior", ui->Lprice_Superior->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_Superior_clicked()
{
    allData::changeRoomData("Lisboa", "Superior", (unsigned int)(ui->Lamout_Superior->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsaveintroduction_Deluxe_clicked()
{
    allData::changeRoomData("Lisboa", "Deluxe", ui->Lintroduction_Deluxe->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_Deluxe_clicked()
{
    allData::changeRoomData("Lisboa", "Deluxe", ui->Lprice_Deluxe->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_Deluxe_clicked()
{
    allData::changeRoomData("Lisboa", "Deluxe", ( unsigned int)(ui->Lamout_Deluxe->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsaveintroduction_SuperiorLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "SuperiorLakeView", ui->Lintroduction_SuperiorLakeView->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_SuperiorLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "SuperiorLakeView", ui->Lprice_SuperiorLakeView->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_SuperiorLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "SuperiorLakeView", (unsigned int)(ui->Lamout_SuperiorLakeView->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsaveintroduction_Corner_clicked()
{
    allData::changeRoomData("Lisboa", "Corner", ui->Lintroduction_Corner->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_Corner_clicked()
{
    allData::changeRoomData("Lisboa", "Corner", ui->Lprice_Corner->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_Corner_clicked()
{
    allData::changeRoomData("Lisboa", "Corner", (unsigned int)(ui->Lamout_Corner->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsaveintroduction_PremierDeluxe_clicked()
{
    allData::changeRoomData("Lisboa", "PremierDeluxe", ui->Lintroduction_PremierDeluxe->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_PremierDeluxe_clicked()
{
    allData::changeRoomData("Lisboa", "PremierDeluxe", ui->Lprice_PremierDeluxe->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_PremierDeluxe_clicked()
{
    allData::changeRoomData("Lisboa", "PremierDeluxe", (unsigned int)(ui->Lamout_PremierDeluxe->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsaveintroduction_PremierLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "PremierLakeView", ui->Lintroduction_PremierLakeView->toPlainText());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetprice_PremierLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "PremierLakeView", ui->Lprice_PremierLakeView->value());
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_Lsetrooms_PremierLakeView_clicked()
{
    allData::changeRoomData("Lisboa", "PremierLakeView", (unsigned int)(ui->Lamout_PremierLakeView->value()));
    QMessageBox::information(0,"NOTICE","SUCCESS",QMessageBox::Close);
}

void lisboawin::on_checkButton_1_clicked()
{
    QDate date = ui->calendarWidget->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "Superior");
    int Order = allData::getRoomOrderNum("L1", date);
    ui->Lorder_Superior->setText(QString("%1").arg(Order));
}

void lisboawin::on_checkButton_2_clicked()
{
    QDate date = ui->calendarWidget_2->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "Deluxe");
    int Order = allData::getRoomOrderNum("L2", date);
    ui->Lorder_Deluxe->setText(QString("%1").arg(Order));
}

void lisboawin::on_checkButton_3_clicked()
{
    QDate date = ui->calendarWidget_3->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "SuperiorLakeView");
    int Order = allData::getRoomOrderNum("L3", date);
    ui->Lorder_SuperiorLakeView->setText(QString("%1").arg(Order));
}

void lisboawin::on_checkButton_4_clicked()
{
    QDate date = ui->calendarWidget_4->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "Corner");
    int Order = allData::getRoomOrderNum("L4", date);
    ui->Lorder_Corner->setText(QString("%1").arg(Order));
}

void lisboawin::on_checkButton_5_clicked()
{
    QDate date = ui->calendarWidget_5->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "PremierDeluxe");
    int Order = allData::getRoomOrderNum("L5", date);
    ui->Lorder_PremierDeluxe->setText(QString("%1").arg(Order));
}

void lisboawin::on_checkButton_6_clicked()
{
    QDate date = ui->calendarWidget_6->selectedDate();
    hotelroom thisroom;
    allData::getRoomData(thisroom, "Lisboa", "PremierLakeView");
    int Order = allData::getRoomOrderNum("L6", date);
    ui->Lorder_PremierLakeView->setText(QString("%1").arg(Order));
}

void lisboawin::on_pushButton_clicked()
{
    this->close();
}
