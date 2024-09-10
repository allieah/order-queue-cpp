#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include "orderdialog.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setStyleSheet("background-color:#87cefa;");
    // Set the background color of all buttons
    QString buttonStyle = "QPushButton {"
                          "background-color: #D5DBDB;" // Dark Blue
                          "color: black;" // Text color i
                          "}"
                          "QPushButton:hover {"
                          "background-color: #6ab5c4;" // Hover colour
                          "color: white;" // Text color changes to white during hover
                          "}";

    ui->btnAddOrder->setStyleSheet(buttonStyle);
    ui->btnCompleteOrder->setStyleSheet(buttonStyle);
    ui->btnNextOrder->setStyleSheet(buttonStyle);
    ui->btnShowOrders->setStyleSheet(buttonStyle);
    ui->btnShowCompletedOrders->setStyleSheet(buttonStyle);
    ui->btnSaveOrdersToFile->setStyleSheet(buttonStyle);
 ui->btnSaveOrdersToFile->setStyleSheet(buttonStyle);
     ui->btnCheckOrderStatus->setStyleSheet(buttonStyle);
      ui->btnExit->setStyleSheet(buttonStyle);

       ui->lineEditOrderID->setStyleSheet("background-color:white;");


    // Connecting the buttons to functions
    connect(ui->btnAddOrder, SIGNAL(clicked()), this, SLOT(addOrder()));//enqueue
    connect(ui->btnCompleteOrder, SIGNAL(clicked()), this, SLOT(completeOrder()));//dequeue
    connect(ui->btnNextOrder, SIGNAL(clicked()), this, SLOT(viewNextOrder()));// view 1st order in queue
    connect(ui->btnShowOrders, SIGNAL(clicked()), this, SLOT(showOrders()));// display queue
    connect(ui->btnShowCompletedOrders, SIGNAL(clicked()), this, SLOT(showCompletedOrders()));// iterate through the queue
    connect(ui->btnSaveOrdersToFile, SIGNAL(clicked()), this, SLOT(saveCompletedOrdersToFile()));
    connect(ui->btnExit, SIGNAL(clicked()), this, SLOT(exitApplication()));

    connect(ui->btnCheckOrderStatus, SIGNAL(clicked()), this, SLOT(checkOrderStatus()));

     currentOrderID = 1;
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::pushOrder(const string& orderDetails)
{
    if (rear == 9) {
        QMessageBox::information(this, "Queue Full", "Cannot add more orders.");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    orderQueue[++rear] = orderDetails;
}

void MainWindow::popOrder()
{
    if (front == -1) {
        QMessageBox::information(this, "No Orders", "No pending orders.");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        ++front;
    }
}
void MainWindow::addOrder()
{
    // Create a form
    OrderDialog dialog(this);
    dialog.setOrderID(currentOrderID);

    // Show the dialog
    if (dialog.exec() == QDialog::Accepted)
    {
        // Retrieve order details
        QString itemName = dialog.getItemName();
        int quantity = dialog.getQuantity();
        int tableNumber = dialog.getTableNumber();
        QString specialRequests = dialog.getSpecialRequests();

        // Construct the order string
        string orderDetails = " ID:"+to_string(currentOrderID)+", Dish: " + itemName.toStdString() +
                                   ", Quantity: " + to_string(quantity) +
                                   ", Table: " +to_string(tableNumber) +
                                   ", Special Requests: " + specialRequests.toStdString();

        // Add to the queue
       pushOrder(orderDetails);

        // Update order status
        ui->lblOrderStatus->setText("Order added : \n" + QString::fromStdString(orderDetails));
        currentOrderID++;
    }
}

void MainWindow::completeOrder()
{if (front != -1)
    {

        QString completedOrder = QString::fromStdString(orderQueue[front]);
        qDebug() << "Completed Order: " << completedOrder;
        popOrder();

        ui->lblOrderStatus->setText("Order completed: \n" + completedOrder);
        count++;
        if (front > rear) {
            front = rear = -1;
        }

        completedOrders.append(completedOrder);
    }
    else
    {
        // If queue is empty
        QMessageBox::information(this, "No Orders", "No pending orders.");
    }
}
void MainWindow::showOrders()
{
    if (front != -1)
    {
        // string with all the pending orders
        string orders;
        for (int i = front; i <= rear; ++i)
        {
            orders += orderQueue[i] + "\n";
        }


        QMessageBox::information(this, "Pending Orders", QString::fromStdString(orders));
    }
    else
    {
        QMessageBox::information(this, "No Orders", "No pending orders.");
    }
}
void MainWindow::showCompletedOrders()
{
    if (completedOrders.isEmpty())
    {
        QMessageBox::information(this, "No Completed Orders", "No completed orders yet.");
    }
    else
    {     // current date and time
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
        QString completedOrdersText = "Completed Orders at "+dateTimeString+":\n";
        for (const QString& order : completedOrders)
        {
            completedOrdersText += order + "\n";
        }

        QMessageBox::information(this, "Completed Orders", completedOrdersText);
    }
}

void MainWindow::saveCompletedOrdersToFile()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Completed Orders", "", "Text Files (*.txt)");

    if (!filePath.isEmpty())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);


            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

            out << "Date and Time: " << dateTimeString << "\n";
            for (const QString& order : completedOrders)
            {
                out << order << "\n";
            }
            file.close();
        }
    }
}

void MainWindow::viewNextOrder()
{
    if (front != -1)
    {
        QString nextOrder = QString::fromStdString(orderQueue[front]);
        ui->lblOrderStatus->setText("Next Order: " + nextOrder);
    }
    else
    {
        QMessageBox::information(this, "No Orders", "No pending orders.");
    }
}
void MainWindow::exitApplication()
{
    qApp->exit();
}

void MainWindow::checkOrderStatus()
{
    int orderID = ui->lineEditOrderID->text().toInt(); // Get order ID that s entered

    // Check if the order ID is valid
    if (orderID >= currentOrderID || orderID < 1) {
        QMessageBox::information(this, "Invalid Order ID", "Please enter a valid order ID.");
        return;
    }

//    if (orderID <currentOrderID && front==-1) {
//        ui->lblOrderStatus->setText("Order ID " + QString::number(orderID) + " is completed.");
//        return;
//    }

    // Check if the order is completed or pending
    if (count>=orderID ) {
          ui->lblOrderStatus->setText("Order ID " + QString::number(orderID) + " is completed.");

    } else {
           ui->lblOrderStatus->setText("Order ID " + QString::number(orderID) + " is pending.");

    }
}
