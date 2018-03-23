#include "mainwindow.h"
#include "logindialog.h"
#include "c_init_bd.h"

#include <QApplication>
#include <QFile>
#include <set>
using namespace std;

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

    //Question 1
    set<int> qSet1;
    qSet1.insert(89);
    qSet1.insert(85);
    qSet1.insert(74);
    qSet1.insert(23);
    qSet1.insert(86);
    qSet1.insert(95);

    set<int> qSet2;
    qSet2.insert(0);
    qSet2.insert(6);
    qSet2.insert(12);
    qSet2.insert(18);
    qSet2.insert(22);

    set<int> qSet3;
    qSet3.insert(qSet1.begin(), qSet1.end());
    qSet3.insert(qSet2.begin(), qSet2.end());

    set<int>::iterator ite;
    QString result = "[";
    for (int e : qSet3) {
        result += " " + QString::number(e) + " ";
    }
    result += "]";
    QMessageBox::information(0, "Résultat Question 1", "Set fusionné = " + result);
    //End question 1


    //Shows the main window only if the login is correct
    if (d.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }

    return 0;
}
