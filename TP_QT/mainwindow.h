#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addclientdialog.h"
#include "addresourcedialog.h"
#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void showAddClientDialog();
    void showAddResourceDialog();
    void showAboutDialog();

    void on_fromDateSearchDateEdit_userDateChanged(const QDate &date);

private:
    void refreshStaffView();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
