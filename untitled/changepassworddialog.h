#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class changepassworddialog;
}

class changepassworddialog : public QDialog
{
    Q_OBJECT

public:
    explicit changepassworddialog(int UserID, QWidget *parent = 0);
    ~changepassworddialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::changepassworddialog *ui;
    int myUserID;
    QString myUsername;
    QString myPassword;
};

#endif // CHANGEPASSWORDDIALOG_H
