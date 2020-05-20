#include "signupinterface.h"
#include "ui_signupinterface.h"
#include "mydatabase.h"
#include "alldata.h"

#include <QMessageBox>

signupinterface::signupinterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupinterface)
{
    ui->setupUi(this);
}

signupinterface::~signupinterface()
{
    delete ui;
}

void signupinterface::on_SignupButton_clicked()                //用戶註冊動作
{
    QString username_signup = ui->reg_UsernameEdit->text();    //獲取輸入的用戶名
    QString password_signup = ui->reg_PasswordEdit->text();    //獲取輸入的密碼
    QString pwdagain = ui->reg_AgainEdit->text();              //獲取輸入的確認密碼

    if(username_signup == "")
    {
        QMessageBox::critical(0,"Warning","Please input your username.",QMessageBox::Ok);
    }
    else if(password_signup == "")
    {
        QMessageBox::critical(0,"Warning","Please input your password.",QMessageBox::Ok);
    }
    else if(password_signup != pwdagain)
    {
        QMessageBox::critical(0,"Warning","Two PassWords are diffirent, please input again.",QMessageBox::Ok);
    }
    else
    {
        if(!allData::checkCustomerUser(username_signup))
        {
            allData::addCustomer(username_signup, password_signup);
            this->close();
        }
        else
        {
            QMessageBox::critical(0,"Warning","This username is existed.",QMessageBox::Ok);
        }
    }
}

