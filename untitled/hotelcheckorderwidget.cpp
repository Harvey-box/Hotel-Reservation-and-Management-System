#include "hotelcheckorderwidget.h"
#include "ui_hotelcheckorderwidget.h"
#include "alldata.h"

hotelcheckorderwidget::hotelcheckorderwidget(int orderid, QWidget *parent) :
    QWidget(parent), thisID(orderid),
    ui(new Ui::hotelcheckorderwidget)
{
    ui->setupUi(this);
    thisorder = allData::getOrder(thisID);
    ui->L_id->setText(QString("%1").arg(thisorder->getOrderID()));
    ui->L_price->setText(QString("%1").arg(thisorder->getprice()));
    ui->L_start->setText(thisorder->getStartDate().toString("yyyy-MM-dd"));
    ui->L_end->setText(thisorder->getEndDate().toString("yyyy-MM-dd"));
    ui->L_status->setText(thisorder->getStatus());
}

hotelcheckorderwidget::~hotelcheckorderwidget()
{
    delete ui;
}

void hotelcheckorderwidget::on_pushButton_clicked()
{
    allData::cancelOrder(thisID);
    thisorder = allData::getOrder(thisID);
    ui->L_id->setText(QString("%1").arg(thisorder->getOrderID()));
    ui->L_price->setText(QString("%1").arg(thisorder->getprice()));
    ui->L_start->setText(thisorder->getStartDate().toString());
    ui->L_end->setText(thisorder->getEndDate().toString());
    ui->L_status->setText(thisorder->getStatus());
}
