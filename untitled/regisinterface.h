#ifndef REGISINTERFACE_H
#define REGISINTERFACE_H

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class regisinterface
{
public:
    regisinterface();
    ~regisinterface();
private:
    QLabel *setUsername;
    QLabel *setPassword;
    QLabel *setPasswordagain;
    QLineEdit *UsernameEdit;
    QLineEdit *PasswordEdit;
    QLineEdit *PasswordagainEdit;
    QPushButton *regisButton;
};

#endif // REGISINTERFACE_H
