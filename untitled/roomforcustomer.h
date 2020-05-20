#ifndef ROOMFORCUSTOMER_H
#define ROOMFORCUSTOMER_H

#include <QWidget>
#include <QString>

namespace Ui {
class roomforcustomer;
}

class roomforcustomer : public QWidget
{
    Q_OBJECT

public:
    explicit roomforcustomer(QWidget *parent, QString newHotelName, QString newRoomType,
                             QString newRoomIntroduction, double newRoomPrice, unsigned int newRoomAmount,
                             QString newImageAddress, QString newroomid, int newcustomerid);
    ~roomforcustomer();
    void setAll(QString newHotelName, QString newRoomType, QString newRoomIntroduction, double newRoomPrice,
                unsigned int newRoomAmount, QString newImageAddress, QString newroomid, int newcustomerid);

private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::roomforcustomer *ui;

    QString HotelName;
    QString RoomType;
    QString RoomIntroduction;
    double RoomPrice;
    unsigned int RoomAmount;
    QString ImageAddress;
    QString RoomID;
    int CustomerID;
};

#endif // ROOMFORCUSTOMER_H
