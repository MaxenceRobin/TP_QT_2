#ifndef ADDCLIENTDIALOG_H
#define ADDCLIENTDIALOG_H

#include <QDialog>
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

private slots:
    void checkBeforeSubmit();
};

#endif // ADDCLIENTDIALOG_H
