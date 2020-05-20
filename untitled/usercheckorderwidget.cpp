#include "usercheckorderwidget.h"
#include "ui_usercheckorderwidget.h"
#include"alldata.h"

usercheckorderwidget::usercheckorderwidget(int orderID, QWidget *parent) :
    QWidget(parent), thisID(orderID),
    ui(new Ui::usercheckorderwidget)
{
    ui->setupUi(this);
    thisorder = allData::getOrder(orderID);
    ui->label_id->setText(QString("%1").arg(thisorder->getOrderID()));
    ui->label_hotel->setText(thisorder->gethotelname());
    ui->label_room->setText(thisorder->getroomtype());
    ui->label_price->setText(QString("%1").arg(thisorder->getprice()));
    ui->label_start->setText(thisorder->getStartDate().toString());
    ui->label_end->setText(thisorder->getEndDate().toString());
    ui->label_status->setText(thisorder->getStatus());
}

usercheckorderwidget::~usercheckorderwidget()
{
    delete ui;
}

void usercheckorderwidget::on_pushButton_clicked()
{
    allData::cancelOrder(thisID);
    thisorder = allData::getOrder(thisID);
    ui->label_id->setText(QString("%1").arg(thisorder->getOrderID()));
    ui->label_hotel->setText(thisorder->gethotelname());
    ui->label_room->setText(thisorder->getroomtype());
    ui->label_price->setText(QString("%1").arg(thisorder->getprice()));
    ui->label_start->setText(thisorder->getStartDate().toString());
    ui->label_end->setText(thisorder->getEndDate().toString());
    ui->label_status->setText(thisorder->getStatus());
}
