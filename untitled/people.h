#ifndef PEOPLE_H
#define PEOPLE_H

#include <QString>

class people            //人的信息,包括顧客與管理員(7/27建立)
{
public:
    people();
    ~people();
    QString getUsername();
    QString getPassword();
protected:
    QString Username;
    QString Password;
};


class customer : public people
{
public:
    customer();
    customer(QString newUsername, QString newPassword);
    customer(QString newUsername, QString newPassword, int newid);
    ~customer();
    void changePW(QString newPassword);
    void addData(QString newusername, QString newpassword, int newid);
    int getcustomerid();
    static int CusNumber;
private:
    int ID;
};



class hotel : public people
{
public:
    hotel();
    ~hotel();
    void addData(QString newUsername, QString newPassword);
private:
    static int HolNumber;
};




#endif // PEOPLE_H
