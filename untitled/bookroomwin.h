#ifndef BOOKROOMWIN_H
#define BOOKROOMWIN_H

#include <QWidget>
#include <QDate>

namespace Ui {
class bookroomwin;
}

class bookroomwin : public QWidget
{
    Q_OBJECT

public:
    explicit bookroomwin(QWidget *parent, QString newHotelName, QString newRoomType, double newRoomPrice,
                         unsigned int newRoomAmount, QString newRoomID, int newCustomerID);
    ~bookroomwin();

private slots:
    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::bookroomwin *ui;

    int Available;
    QString HotelName;
    QString RoomType;
    double RoomPrice;
    unsigned int RoomAmount;
    QString RoomID;
    int CustomerID;
    double total;
    QDate startdate;
    QDate enddate;
};

#endif // BOOKROOMWIN_H
