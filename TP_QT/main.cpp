#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog d;

    if (d.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;
}
