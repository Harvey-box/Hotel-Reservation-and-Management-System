#ifndef SIGNUPINTERFACE_H
#define SIGNUPINTERFACE_H

#include <QDialog>

namespace Ui {
class signupinterface;
}

class signupinterface : public QDialog          //註冊界面(7/27建立)
{
    Q_OBJECT

public:
    explicit signupinterface(QWidget *parent = 0);
    ~signupinterface();

private slots:
    void on_SignupButton_clicked();             //進行註冊動作

private:
    Ui::signupinterface *ui;
};

#endif // SIGNUPINTERFACE_H
