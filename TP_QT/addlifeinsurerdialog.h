#ifndef ADDLIFEINSURERDIALOG_H
#define ADDLIFEINSURERDIALOG_H

#include <QDialog>

namespace Ui {
class AddLifeInsurerDialog;
}

class AddLifeInsurerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLifeInsurerDialog(QWidget *parent = 0);
    ~AddLifeInsurerDialog();

private slots:
    void on_addPushButton_clicked();

private:
    Ui::AddLifeInsurerDialog *ui;
};

#endif // ADDLIFEINSURERDIALOG_H
