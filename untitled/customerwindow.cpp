#include "customerwindow.h"
#include "ui_customerwindow.h"

customerwindow::customerwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customerwindow)
{
    ui->setupUi(this);
}

customerwindow::~customerwindow()
{
    delete ui;
}
