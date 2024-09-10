#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addOrder();
    void completeOrder();
     void showOrders();
     void showCompletedOrders();
     void saveCompletedOrdersToFile();
    void viewNextOrder();
     void checkOrderStatus();
     void pushOrder(const string& orderDetails);
     void popOrder();
     void exitApplication();


private:
    Ui::MainWindow *ui;
    string orderQueue[10]; // Array to hold orders
    int front=-1;
    int rear=-1;
    int count=0;
    int currentOrderID;
    QStringList completedOrders; // List to hold completed orders
};
#endif
