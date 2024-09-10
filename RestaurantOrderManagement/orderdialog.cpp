#include "orderdialog.h"
#include "ui_orderdialog.h"

OrderDialog::OrderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderDialog)
{
     this->setStyleSheet("background-color:white;");
    ui->setupUi(this);

     connect(ui->btnPlaceOrder, SIGNAL(clicked()), this, SLOT(placeOrder()));
}

OrderDialog::~OrderDialog()
{
    delete ui;
}



QString OrderDialog::getItemName()
{
    return ui->txtName->text();
}

void OrderDialog::setOrderID(int id)
{
    ui->lineEditOrderID->setText(QString::number(id));
}
int OrderDialog::getQuantity()
{
    return ui->spinQuantity->value();
}

int OrderDialog::getTableNumber()
{
    return ui->spinTableNo->value();
}

QString OrderDialog::getSpecialRequests()
{
    return ui->txtSpecialR->text();
}

void OrderDialog::placeOrder()
{
    accept();
}
