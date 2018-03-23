#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addclientdialog.h"
#include "addresourcedialog.h"
#include "aboutdialog.h"
#include "clientssortfilterproxymodel.h"

namespace Ui {
class MainWindow;
}


/**
 * @brief The MainWindow class
 */
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

    void on_resetPushButton_clicked();

    void showUpdateResource(QModelIndex index);

    void showUpdateClient(QModelIndex index);

    void on_deleteResourcePushButton_clicked();

    void on_resourcesTreeView_clicked(const QModelIndex &index);

    void on_deleteClientPushButton_clicked();

    void on_clientTableView_clicked(const QModelIndex &index);

private:
    void refreshResourceView();
    void refreshClientsView();
    Ui::MainWindow *ui;
    QSqlQueryModel *clientsModel;
    ClientsSortFilterProxyModel *clientsProxyModel;
};

#endif // MAINWINDOW_H
