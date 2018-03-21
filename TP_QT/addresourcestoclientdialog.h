#ifndef ADDRESOURCESTOCLIENTDIALOG_H
#define ADDRESOURCESTOCLIENTDIALOG_H

#include <QDialog>
#include "resource.h"

namespace Ui {
class AddResourcesToClientDialog;
}

class AddResourcesToClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddResourcesToClientDialog(QWidget *parent = 0);
    ~AddResourcesToClientDialog();

private:
    Ui::AddResourcesToClientDialog *ui;

private slots:
    void refreshResourcesTableView();
    void createResourcesList();

signals:

    void newRessources(QList<Resource> resources);
};

#endif // ADDRESOURCESTOCLIENTDIALOG_H
