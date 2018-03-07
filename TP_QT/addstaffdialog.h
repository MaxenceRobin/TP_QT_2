#ifndef ADDSTAFFDIALOG_H
#define ADDSTAFFDIALOG_H

#include <QDialog>

namespace Ui {
class AddStaffDialog;
}

class AddStaffDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStaffDialog(QWidget *parent = 0);
    ~AddStaffDialog();

private:
    Ui::AddStaffDialog *ui;

private slots:
    void checkBeforeSubmit();
    void on_typeComboBox_currentIndexChanged(int index);
};

#endif // ADDSTAFFDIALOG_H
