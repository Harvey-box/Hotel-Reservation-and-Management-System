#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupinterface.h"
#include "lisboawin.h"
#include "parisianwin.h"
#include "venetianwin.h"
#include "emperorwin.h"
#include "alldata.h"
#include "customerwin.h"
#include "adminwin.h"

#include <QLabel>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(470,300);
    this->setWindowTitle("Login interface");


    //標籤--帳號密碼
    myUsername = new QLabel("UserName: ",this);
    myUsername->setGeometry(210,80,70,30);
    myPassword = new QLabel("Password: ",this);
    myPassword->setGeometry(210,110,70,30);

    //文本輸入框
    myNameedit = new QLineEdit(this);
    myNameedit->setGeometry(280,85,100,20);            //定Username輸入框位置及大小
    myNameedit->setMaxLength(8);                        //Username最大輸入長度為8
    myPassedit = new QLineEdit(this);
    myPassedit->setGeometry(280,115,100,20);            //定Password輸入框位置及大小
    myPassedit->setMaxLength(12);                       //Password最大輸入長度為12
    myPassedit->setEchoMode(QLineEdit::Password);       //設定為密碼模式
    myPassedit->setFont(QFont("",10,QFont::Black));     //設定字體大小及顏色

    //登陸按鈕
    loginButton = new QPushButton("Log in",this);
    loginButton->setGeometry(255,145,60,30);
    connect(loginButton,&QPushButton::clicked, this, &MainWindow::login);
    loginButton_h = new QPushButton("Log in (for hotel)",this);
    loginButton_h->setGeometry(255,180,125,30);
    connect(loginButton_h, &QPushButton::clicked, this, &MainWindow::login_h);


    //註冊按鈕
    regisButton = new QPushButton("Sign up",this);
    regisButton->setGeometry(320,145,60,30);
    connect(regisButton,&QPushButton::clicked, this, &MainWindow::regis);


    //圖片
    mypicture = new QLabel(this);
    mypicture->setScaledContents(true);
    QPixmap pix = QPixmap("://images/user.jpg");
    mypicture->setGeometry(70,80,120,130);
    mypicture->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::login()
{
    QString strU = myNameedit->text();                  //取出輸入的UserName
    QString strP = myPassedit->text();                  //取出輸入的Password

    //確認輸入不為空
    if(strU == NULL)
    {
        QMessageBox::critical(0,"Warning","Please input your username.",QMessageBox::Ok);
    }
    else if(strP == NULL)
    {
        QMessageBox::critical(0,"Warning","Please input your password.",QMessageBox::Ok);
    }else   if(strU == "Admin")
    {
        if(strP == "admin")
        {
            this->close();

            adminwin* adwin = new adminwin;
            adwin->show();
        }else
        {
            QMessageBox::critical(0,"WARNING","Please check you Username and Password!",QMessageBox::Close);
        }
    }else   if(allData::checkCustomerPW(strU, strP))
    {
        this->close();

        customerwin* userwin = new customerwin(strU ,allData::getCustomerID(strU));
        userwin->show();
    }else
    {
        QMessageBox::critical(0,"WARNING","Please check you Username and Password!",QMessageBox::Close);
    }
}

void MainWindow::login_h()
{
    QString strU = myNameedit->text();                  //取出輸入的UserName
    QString strP = myPassedit->text();                  //取出輸入的Password

    //確認輸入不為空
    if(strU == NULL)
    {
        QMessageBox::critical(0,"Warning","Please input your username.",QMessageBox::Ok);
    }
    else if(strP == NULL)
    {
        QMessageBox::critical(0,"Warning","Please input your password.",QMessageBox::Ok);
    }else if((strU == "Lisboa") && (allData::checkHotelPW("Lisboa", strP)))
    {
        this->close();
        lisboawin *win = new lisboawin();
        win->show();
    }
    else if((strU == "Parisian") && (allData::checkHotelPW("Parisian", strP)))
    {
        this->close();
        parisianwin *win = new parisianwin();
        win->show();
    }
    else if((strU == "Venetian") && (allData::checkHotelPW("Venetian", strP)))
    {
        this->close();
        venetianwin *win = new venetianwin();
        win->show();
    }
    else if((strU == "Emperor") && (allData::checkHotelPW("Emperor", strP)))
    {
        this->close();
        emperorwin *win = new emperorwin();
        win->show();
    }
    else
    {
        QMessageBox::critical(0,"WARNING","Please check you Username and Password!",QMessageBox::Close);
    }
}

void MainWindow::regis()                                //打開註冊界面
{
    signupinterface *signupwin = new signupinterface();
    signupwin->show();
}
