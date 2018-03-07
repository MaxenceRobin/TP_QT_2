#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <iostream>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void connect();

private:
    Ui::LoginDialog *ui;
    bool checkLogin();
};

#endif // LOGINDIALOG_H
