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
    explicit AddClientDialog(int idClient = -1, QWidget *parent = 0);
    ~AddClientDialog();

private:
    Ui::AddClientDialog *ui;
    int mIdClient;
    AddResourcesToClientDialog *resourceDialog;

private slots:
    void addResources();
    void checkBeforeSubmit();
    void getNewResources(QList<Resource> resources);
};

#endif // ADDCLIENTDIALOG_H
