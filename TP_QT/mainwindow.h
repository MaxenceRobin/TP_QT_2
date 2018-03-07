#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addclientdialog.h"
#include "addstaffdialog.h"
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
    void showAddStaffDialog();
    void showAboutDialog();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
