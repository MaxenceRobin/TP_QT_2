#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = 0);
    ~AddClient();

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
