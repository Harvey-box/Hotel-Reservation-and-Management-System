#include "userinformation.h"
#include "ui_userinformation.h"
#include "alldata.h"
#include "changepassworddialog.h"

#include <QDebug>

userinformation::userinformation(QString username, int id, QWidget *parent) :
    QWidget(parent), myUserName(username), myUserID(id),
    ui(new Ui::userinformation)
{
    ui->setupUi(this);
    this->setFixedSize(1000,650);
    ui->label_ID->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_Hotel->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_RoomType->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_Price->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_Start->setStyleSheet("background-color:rgb(255,255,255)");
    ui->label_End->setStyleSheet("background-color:rgb(255,255,255)");

    ui->label_user->setText(myUserName);
    allData::getOrder(myallorder, myUserID);
    getmyOrderWin();

    for(int i=0; i<myorderwin.size(); i++)
    {
        ui->order_show->addWidget(myorderwin[i]);
    }
}

userinformation::~userinformation()
{
    delete ui;
}


void userinformation::getmyOrderWin()
{
    for(int i=0; i<myallorder.size(); i++)
    {
        usercheckorderwidget* newWid;
        newWid = new usercheckorderwidget(myallorder[i].getOrderID());
        myorderwin.push_back(newWid);
        qDebug() << myallorder[i].gethotelname() << myallorder[i].getprice();
    }
}

void userinformation::on_pushButton_clicked()
{
    changepassworddialog *newdialog;
    newdialog = new changepassworddialog(myUserID);
    newdialog->show();
}
