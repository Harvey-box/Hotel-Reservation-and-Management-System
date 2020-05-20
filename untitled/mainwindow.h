#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow   //登錄界面(7/26建立)
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *myUsername;
    QLabel *myPassword;
    QLabel *mypicture;
    QLineEdit *myNameedit;
    QLineEdit *myPassedit;
    QPushButton *loginButton;
    QPushButton *loginButton_h;
    QPushButton *regisButton;

public slots:
    void login();                       //用戶登入
    void login_h();
    void regis();                       //用戶註冊
};

#endif // MAINWINDOW_H
