#include "orderwidget.h"
#include "ui_orderwidget.h"

orderwidget::orderwidget(order neworder, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderwidget)
{
    myorder = neworder;
    ui->setupUi(this);
    ui->label_id->setText(QString::number(myorder.getOrderID()));


}

orderwidget::~orderwidget()
{
    delete ui;
}
