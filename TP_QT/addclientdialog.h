#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H
#include "addresourcestoclientdialog.h"
#include <QDialog>
#include <QListWidget>
#include <string>
using namespace std;

namespace Ui {
class AddClientDialog;
}

class AddClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClientDialog(QWidget *parent = 0);
    ~AddClientDialog();

private:
    Ui::AddClientDialog *ui;
    AddResourcesToClientDialog *resourceDialog;

private slots:
    void addResources();
    void checkBeforeSubmit();
    void getNewResources(QModelIndexList model);
};

#endif // ADDCLIENTDIALOG_H
