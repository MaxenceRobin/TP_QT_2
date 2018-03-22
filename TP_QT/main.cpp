#include "mainwindow.h"
#include "logindialog.h"
#include "c_init_bd.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog d;

    // If the db still doesn't exist, it has to be created
    if (!QFile::exists("base_tmp.sqli"))
    {
        C_INIT_BD::Creation_BD();
    }

    if (d.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }

    return 0;
}
