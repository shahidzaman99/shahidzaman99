#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Class to manage individual products in the inventory
class LinkedListInventory {
private:
    struct Product {
        string name;
        double price;
        int stock;
        Product* next;
    };
    Product* head;

public:
    LinkedListInventory() : head(0) {}

    ~LinkedListInventory() {
        Product* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(string name, double price, int stock) {
        Product* newProduct = new Product{name, price, stock, 0};
        if (!head) {
            head = newProduct;
        } else {
            Product* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
    }

    void displayProducts() {
        cout << left << setw(20) << "Product Name" << setw(10) << "Stock" << setw(10) << "Price" << endl;
        cout << string(40, '-') << endl;
        Product* temp = head;
        while (temp) {
            cout << left << setw(20) << temp->name << setw(10) << temp->stock << "$" << fixed << setprecision(2) << temp->price << endl;
            temp = temp->next;
        }
        cout << string(40, '-') << endl;
    }

    void removeProduct(string name) {
        if (!head) {
            cout << "Product not found!" << endl;
            return;
        }

        if (head->name == name) {
            Product* temp = head;
            head = head->next;
            delete temp;
            cout << "Product removed successfully!" << endl;
            return;
        }

        Product* current = head;
        Product* previous = 0;
        while (current && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
            cout << "Product removed successfully!" << endl;
        } else {
            cout << "Product not found!" << endl;
        }
    }

    void searchProduct(string name) {
        Product* temp = head;
        bool found = false;
        while (temp) {
            if (temp->name == name) {
                found = true;
                cout << "Product: " << temp->name << ", Price: $" << temp->price << ", Stock: " << temp->stock << endl;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "Product not found!" << endl;
        }
    }

    // New Method: Handles product purchase
    bool purchaseProduct(string name, int quantity, double &totalPrice) {
        Product* temp = head;
        while (temp) {
            if (temp->name == name) {
                if (temp->stock >= quantity) {
                    totalPrice = temp->price * quantity;
                    temp->stock -= quantity;
                    return true;
                } else {
                    cout << "Insufficient stock for product: " << name << endl;
                    return false;
                }
            }
            temp = temp->next;
        }
        cout << "Product not found!" << endl;
        return false;
    }
};


// Class for managing customers in a queue
struct Customer {
    string name;
    string email;
    double totalSpent;
    Customer* next;
};

class CustomerQueue {
private:
    Customer* front;
    Customer* rear;

public:
    CustomerQueue() : front(0), rear(0) {}

    ~CustomerQueue() {
        while (!isEmpty()) {
            delete dequeueCustomer();
        }
    }

    void enqueueCustomer(string name, string email, double totalSpent) {
        Customer* newCustomer = new Customer{name, email, totalSpent, 0};
        if (!rear) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }
    }

    Customer* dequeueCustomer() {
        if (!front) return 0;
        Customer* temp = front;
        front = front->next;
        if (!front) rear = 0;
        return temp;
    }

    bool isEmpty() {
        return front == 0;
    }
};

// Class for managing low stock alerts using a stack
class Stack {
private:
    struct Node {
        string productName;
        Node* next;
    };
    Node* top;

public:
    Stack() : top(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(string productName) {
        Node* newNode = new Node{productName, top};
        top = newNode;
    }

    string pop() {
        if (!top) return "";
        Node* temp = top;
        string productName = top->productName;
        top = top->next;
        delete temp;
        return productName;
    }

    bool isEmpty() {
        return top == 0;
    }
};

// Class to handle user interactions and management
class UserInterface {
private:
    LinkedListInventory inventory; // Inventory managed by a linked list
    CustomerQueue customerQueue;   // Queue for customer management
    Stack lowStockAlerts;          // Stack for low stock alerts
    double totalSales;
    int totalCustomers;

public:
    string adminUsername = "admin"; // Default admin username
    string adminPassword = "admin"; // Default admin password

    UserInterface() {
        totalSales = 0;
        totalCustomers = 0;
    }

    void adminMenu() {
        string username, password;
        while (true) {
            cout << "Enter Admin Username: ";
            cin >> username;
            cout << "Enter Admin Password: ";
            cin >> password;

            if (username == adminUsername && password == adminPassword) {
                break; // Break if credentials are correct
            } else {
                cout << "Invalid credentials. Please enter valid username and password." << endl;
            }
        }

        int choice;
        do {
            cout << "\nAdmin Actions:\n";
            cout << "1. Change Admin Credentials\n";
            cout << "2. Manage Inventory & Shopping\n";
            cout << "3. Generate Daily Report\n";
            cout << "4. View Low Stock Alerts\n";
            cout << "5. Exit Admin Menu\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
            case 1:
                changeAdminCredentials();
                break;
            case 2:
                manageInventoryShopping();
                break;
            case 3:
                generateDailyReport();
                break;
            case 4:
                viewLowStockAlerts();
                break;
            case 5:
                cout << "Exiting Admin Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 5);
    }

    void changeAdminCredentials() {
        cout << "Enter new username: ";
        cin >> adminUsername;
        cout << "Enter new password: ";
        cin >> adminPassword;
        cout << "Admin credentials changed successfully." << endl;
    }

    void manageInventoryShopping() {
        int choice;
        do {
            cout << "\nMenu:\n";
            cout << "1. Add New Product to Inventory\n";
            cout << "2. Remove Product from Inventory\n";
            cout << "3. Customer Shopping\n";
            cout << "4. View All Products\n";
            cout << "5. View Total Sales\n";
            cout << "6. Search for a Product\n";
            cout << "7. Exit\n";
            cout << "Choose an option: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addNewProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                handleCustomerShopping();
                break;
            case 4:
                inventory.displayProducts();
                break;
            case 5:
                cout << "Total Sales: $" << fixed << setprecision(2) << totalSales << endl;
                break;
            case 6:
                searchForProduct();
                break;
            case 7:
                cout << "Exiting Inventory & Shopping Menu." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (choice != 7);
    }

    void addNewProduct() {
        string name;
        double price;
        int stock;

        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Product Price: ";
        cin >> price;
        cout << "Enter Product Stock: ";
        cin >> stock;

        inventory.addProduct(name, price, stock);
        cout << "Product added successfully!" << endl;
    }

    void removeProduct() {
        string name;
        cout << "Enter Product Name to Remove: ";
        cin >> name;

        inventory.removeProduct(name);
    }

void handleCustomerShopping() {
    string name, email;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Customer Email: ";
    cin >> email;

    double totalSpent = 0.0;
    char moreShopping;
    do {
        string productName;
        int quantity;
        double price;

        cout << "\nAvailable Products:" << endl;
        inventory.displayProducts();
        cout << "Enter the product name to purchase: ";
        cin >> productName;
        cout << "Enter the quantity: ";
        cin >> quantity;

        // Process the purchase and add to total spent
        if (inventory.purchaseProduct(productName, quantity, price)) {
            totalSpent += price;
            cout << "Purchased " << quantity << " of " << productName 
                 << " for $" << fixed << setprecision(2) << price << endl;
        }

        // Ask if the customer wants to buy more products
        cout << "Would you like to buy more products? (y/n): ";
        cin >> moreShopping;
    } while (moreShopping == 'y' || moreShopping == 'Y');

    // Store customer data
    customerQueue.enqueueCustomer(name, email, totalSpent);
    totalSales += totalSpent;
    totalCustomers++;
    cout << "\nTotal Spent by " << name << ": $" << fixed << setprecision(2) << totalSpent << endl;
}


    void generateDailyReport() {
        cout << "Total Customers Served: " << totalCustomers << endl;
        cout << "Total Sales: $" << totalSales << endl;
    }

  void viewLowStockAlerts() {
    if (lowStockAlerts.isEmpty()) {
        cout << "No low stock alerts." << endl;
    } else {
        cout << "Low Stock Alerts:" << endl;
        while (!lowStockAlerts.isEmpty()) {
            cout << "- " << lowStockAlerts.pop() << endl;
        }
    }
}


    void searchForProduct() {
        string name;
        cout << "Enter Product Name to Search: ";
        cin >> name;
        inventory.searchProduct(name);
    }
};

// Main function
int main() {
    UserInterface ui;
    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Admin Login\n";
        cout << "2. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ui.adminMenu();
            break;
        case 2:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}

