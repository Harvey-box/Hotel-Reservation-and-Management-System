#include "people.h"
#include "mydatabase.h"

int customer::CusNumber = 0;
int hotel::HolNumber = 0;

people::people()
{

}

people::~people()
{

}

QString people::getUsername()
{
    return Username;
}

QString people::getPassword()
{
    return Password;
}


hotel::hotel()
{
}

hotel::~hotel()
{

}

void hotel::addData(QString newUsername, QString newPassword)
{
    Username = newUsername;
    Password = newPassword;
}



customer::customer()
{

}

customer::customer(QString newUsername, QString newPassword)
{
    ID = CusNumber-1;
    Username = newUsername;
    Password = newPassword;
}

customer::customer(QString newUsername, QString newPassword, int newid)
{
    ID = newid;
    Username = newUsername;
    Password = newPassword;
}

customer::~customer()
{

}

void customer::addData(QString newusername, QString newpassword, int newid)
{
    Username = newusername;
    Password = newpassword;
    ID = newid;
}

void customer::changePW(QString newPassword)
{
    Password = newPassword;
}

int customer::getcustomerid()
{
    return ID;
}
