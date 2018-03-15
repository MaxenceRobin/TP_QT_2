#include "mainwindow.h"
#include "logindialog.h"
#include "c_init_bd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog d;

    if (d.exec() == QDialog::Accepted)
    {
        C_INIT_BD::Creation_BD();
        w.show();
        return a.exec();
    }
    return 0;
}
