#include "userorder.h"
#include "ui_userorder.h"
#include "alldata.h"

userorder::userorder(int customerid, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userorder)
{
    ui->setupUi(this);
    mycustomerid = customerid;


    allData::getOrder(myorder, mycustomerid);
    for(int i=0; i<myorder.size(); i++)
    {

    }
}

userorder::~userorder()
{
    delete ui;
}
