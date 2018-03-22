#ifndef ADDSTAFFDIALOG_H
#define ADDSTAFFDIALOG_H

#include <QDialog>

namespace Ui {
class AddResourceDialog;
}

class AddResourceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddResourceDialog(int idResource, QWidget *parent = 0);
    ~AddResourceDialog();

private:
    Ui::AddResourceDialog *ui;
    unsigned int mIdResource;

private slots:
    void checkBeforeSubmit();
    void on_typeComboBox_currentIndexChanged();
};

#endif // ADDSTAFFDIALOG_H
