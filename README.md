# Restaurant Order Management System

This project is a **Restaurant Order Management System** built using **C++** and **Qt Creator**. The program manages customer orders using a **queue** structure. It allows users to add, view, and complete orders in a restaurant. Completed orders are saved to a file, and the system can display pending and completed orders.

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [How to Run the Project](#how-to-run-the-project)
- [Functionality](#functionality)
- [Usage Instructions](#usage-instructions)

## Features

- **Queue Implementation**: Orders are stored and processed in a queue (FIFO).
- **Add Orders**: The user can add an order with details such as item name, quantity, table number, and special requests.
- **View Orders**: View the next order in the queue or display all pending orders.
- **Complete Orders**: Mark orders as completed and store them in a list.
- **Save Orders**: Save completed orders to a text file.
- **Order Status**: Check the status of any order by its ID (Pending or Completed).
- **Simple UI**: Custom background and button colors for easier user experience.

## Technologies Used

- **C++**: Programming language for core logic.
- **Qt Framework**: For GUI development.
- **Qt Creator**: IDE used for development.
- **C++17**: Language standard used.

## How to Run the Project

### Prerequisites

1. **Qt Creator**: Install the latest version of Qt Creator.
2. **C++17**: Ensure that you have a C++17 compatible compiler.
3. **Qt Libraries**: The program uses core Qt libraries like `QApplication`, `QMainWindow`, `QDialog`, `QMessageBox`, and more.

### Steps to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/restaurant-order-management.git```
2. Open the project in **Qt Creator**.
3. Build the project using the **C++17** standard.
4. Run the project from **Qt Creator**.

## Functionality

### 1. Adding an Order

- **Input**: The user is prompted to enter the item name, quantity, table number, and special requests.
- **Queue**: The order is added to the queue and displayed in the UI.

### 2. Completing an Order

- The system completes the order at the front of the queue (FIFO), removes it, and marks it as completed.

### 3. Viewing Orders

- **Pending Orders**: Display all orders currently in the queue.
- **Completed Orders**: View all completed orders, along with the date and time.

### 4. Saving Completed Orders

- Completed orders can be saved to a `.txt` file for record-keeping. The file will include the date and time of completion.

### 5. Checking Order Status

- Enter an order ID to check whether it is completed or still pending.

## Usage Instructions

- **Add Order**: Click the "Add Order" button, fill out the form, and submit.
- **Complete Order**: Click the "Complete Order" button to mark the first pending order as complete.
- **View Orders**: Click "Show Orders" to view all pending orders, or "Show Completed Orders" for completed orders.
- **Save Orders**: Click "Save Completed Orders to File" to save a list of completed orders as a `.txt` file.
- **Check Order Status**: Enter an order ID in the provided field and click "Check Order Status" to see if the order is pending or completed.
- **Exit**: Click "Exit" to close the application.

