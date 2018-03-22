#ifndef ADDSTAFFDIALOG_H
#define ADDSTAFFDIALOG_H

#include <QDialog>

namespace Ui {
class AddResourceDialog;
}

enum class UtilisationType
{
    Create,
    Edit
};

class AddResourceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddResourceDialog(UtilisationType type, QWidget *parent = 0);
    ~AddResourceDialog();

private:
    Ui::AddResourceDialog *ui;
    UtilisationType mType;

private slots:
    void checkBeforeSubmit();
    void on_typeComboBox_currentIndexChanged();
};

#endif // ADDSTAFFDIALOG_H
