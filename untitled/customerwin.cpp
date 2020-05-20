#include "customerwin.h"
#include "ui_customerwin.h"
#include "roomforcustomer.h"
#include "alldata.h"
#include "hoteldata.h"
#include "userinformation.h"

#include <QAction>
#include <QMenu>
#include <QWidget>
#include <QDebug>
#include <QLayout>

customerwin::customerwin(QString username, int id, QWidget *parent) :
    QWidget(parent), userid(id), myusername(username),
    ui(new Ui::customerwin)
{
    ui->setupUi(this);
    ui->UserButton->setText(username);

    QMenu *hotelmenu = new QMenu(this);
    act[0] = new QAction(tr("ALL"),this);
    act[1] = new QAction(tr("Lisboa"),this);
    act[2] = new QAction(tr("Parisian"),this);
    act[3] = new QAction(tr("Venetian"),this);
    act[4] = new QAction(tr("Emperor"),this);
    hotelmenu->addAction(act[0]);
    hotelmenu->addAction(act[1]);
    hotelmenu->addAction(act[2]);
    hotelmenu->addAction(act[3]);
    hotelmenu->addAction(act[4]);
    ui->hotelButton->setMenu(hotelmenu);
    connect(act[0], SIGNAL(triggered(bool)), this, SLOT(allhotel()));
    connect(act[1], SIGNAL(triggered(bool)), this, SLOT(Lisboa()));
    connect(act[2], SIGNAL(triggered(bool)), this, SLOT(Parisian()));
    connect(act[3], SIGNAL(triggered(bool)), this, SLOT(Venetian()));
    connect(act[4], SIGNAL(triggered(bool)), this, SLOT(Emperor()));

    QMenu *arrangment = new QMenu(this);
    slot[0] = new QAction(tr("High ot Low"),this);
    slot[1] = new QAction(tr("Low to High"),this);
    arrangment->addAction(slot[0]);
    arrangment->addAction(slot[1]);
    ui->arranButton->setMenu(arrangment);
    connect(slot[0], SIGNAL(triggered(bool)), this, SLOT(slotdown()));
    connect(slot[1], SIGNAL(triggered(bool)), this, SLOT(slotup()));



    allRoomData = *(allData::getallRoom());
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

customerwin::~customerwin()
{
    delete ui;
}

void customerwin::getRoomWid()
{
    for(int i=0; i<allRoomData.size(); i++)
    {
       roomforcustomer* newWid;
       newWid = new roomforcustomer(0, allRoomData[i].getHotelName(), allRoomData[i].getRoomType(),
                                    allRoomData[i].getIntroduction(), allRoomData[i].getPrice(),
                                    allRoomData[i].getAmount(), allRoomData[i].getimage(),
                                    allRoomData[i].getid(), userid);
       allRoomWid.push_back(newWid);
    }
}

void customerwin::on_UserButton_clicked()
{
    userinformation *Win = new userinformation(myusername, userid);
    Win->show();
}

void customerwin::on_pushButton_clicked()
{
    this->close();
}


void customerwin::allhotel()
{
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();
    allRoomData.clear();
    allRoomData = *(allData::getallRoom());
    getRoomWid();
    qDebug() << allRoomWid.size() << allRoomData.size();
    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::Lisboa()
{
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();
    allRoomData.clear();
    allData::getRoomData(allRoomData,"Lisboa");
    getRoomWid();
qDebug() << allRoomWid.size() << allRoomData.size();
    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::Parisian()
{
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();
    allRoomData.clear();
    allData::getRoomData(allRoomData,"Parisian");
    getRoomWid();
qDebug() << allRoomWid.size() << allRoomData.size();
    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::Venetian()
{
    for(int i=0; i<allRoomWid.size(); i++)
    {
        delete allRoomWid[i];
    }
    allRoomWid.clear();
    allRoomData.clear();
    allData::getRoomData(allRoomData,"Venetian");
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::Emperor()
{
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();
    allRoomData.clear();
    allData::getRoomData(allRoomData,"Emperor");
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::slotdown()
{
    hotelroom item;
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();

    for(int i=0; i<allRoomData.size()-1; i++)
    {
        for(int j=i+1; j<allRoomData.size(); j++)
        {
            if(allRoomData[j].getPrice() > allRoomData[i].getPrice())
            {
                item = allRoomData[i];
                allRoomData[i] = allRoomData[j];
                allRoomData[j] = item;
            }
        }
    }
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}

void customerwin::slotup()
{
    hotelroom item;
    for(int i=0; i<allRoomWid.size(); i++)
    {
//        ui->content->removeWidget(allRoomWid[i]);
        delete allRoomWid[i];
    }
    allRoomWid.clear();

    for(int i=0; i<allRoomData.size()-1; i++)
    {
        for(int j=i+1; j<allRoomData.size(); j++)
        {
            if(allRoomData[j].getPrice() < allRoomData[i].getPrice())
            {
                item = allRoomData[i];
                allRoomData[i] = allRoomData[j];
                allRoomData[j] = item;
            }
        }
    }
    getRoomWid();

    for(int i=0; i<allRoomWid.size(); i++)
    {
        ui->content->addWidget(allRoomWid[i]);
    }
}
