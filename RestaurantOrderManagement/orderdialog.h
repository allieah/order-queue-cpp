#ifndef ORDERDIALOG_H
#define ORDERDIALOG_H

#include <QDialog>

namespace Ui {
class OrderDialog;
}

class OrderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OrderDialog(QWidget *parent = nullptr);
    ~OrderDialog();

    QString getItemName();
    int getQuantity();
    int getTableNumber();
    QString getSpecialRequests();
     void setOrderID(int id);


private slots:
    void placeOrder();

private:
    Ui::OrderDialog *ui;
};

#endif
