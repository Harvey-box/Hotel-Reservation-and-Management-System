#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"
#include "alldata.h"

#include <QMessageBox>

changepassworddialog::changepassworddialog(int UserID, QWidget *parent) :
    QDialog(parent), myUserID(UserID),
    ui(new Ui::changepassworddialog)
{
    ui->setupUi(this);
    this->setFixedSize(400,300);
    myUsername = allData::getCustomerUM(myUserID);
    ui->username->setText(myUsername);
}

changepassworddialog::~changepassworddialog()
{
    delete ui;
}

void changepassworddialog::on_buttonBox_accepted()
{
    QString password;
    QString newpassword;
    QString again;
    password = ui->lineEdit->text();
    if(password == allData::getCustomerPW(myUserID))
    {
        newpassword = ui->lineEdit_2->text();
        again = ui->lineEdit_3->text();
        if(newpassword == again)
        {
            allData::changeUserPW(myUsername, newpassword);
            QMessageBox::information(0,"NOTICE", "Your password has been changed.", QMessageBox::Ok);
        }
        else
        {
            QMessageBox::critical(0,"WARNING", "Please input newpassword again.", QMessageBox::Ok);
        }
    }
    else
    {
        QMessageBox::critical(0,"WARNING", "Your password is wrong.", QMessageBox::Ok);
    }
}
