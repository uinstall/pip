#include <iostream>
#include <string>
//defines a constant called MAX_CUSTOMERS, which is set to 100. 
//It represents the maximum number of customers that can be stored in the array.
#define MAX_CUSTOMERS 100

using namespace std;

// Structure to hold customer information
struct Customer {
    int id;
    string name;
    string contactNumber;
    string address;
};

// Function prototypes
void displayCustomers(Customer customers[], int count);
void insertCustomer(Customer customers[], int &count);
void updateCustomer(Customer customers[], int count);
void deleteCustomer(Customer customers[], int &count);
int findCustomerIndexById(Customer customers[], int count, int id);

int main() {
    Customer customers[MAX_CUSTOMERS];
    int customerCount = 0;
    int choice;

    do {
        // Menu
        cout << "\nCustomer Information Management System\n";
        cout << "1. Display Customers\n";
        cout << "2. Insert Customer\n";
        cout << "3. Update Customer\n";
        cout << "4. Delete Customer\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayCustomers(customers, customerCount);
                break;
            case 2:
                insertCustomer(customers, customerCount);
                break;
            case 3:
                updateCustomer(customers, customerCount);
                break;
            case 4:
                deleteCustomer(customers, customerCount);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to display all customers
void displayCustomers(Customer customers[], int count) {
    if (count == 0) {
        cout << "No customers to display.\n";
    } else {
        cout << "\nCustomer List:\n";
        for (int i = 0; i < count; i++) {
            cout << "ID: " << customers[i].id << "\n"
                 << "Name: " << customers[i].name << "\n"
                 << "Contact Number: " << customers[i].contactNumber << "\n"
                 << "Address: " << customers[i].address << "\n\n";
        }
    }
}

// Function to insert a new customer
void insertCustomer(Customer customers[], int &count) {
    if (count >= MAX_CUSTOMERS) {
        cout << "Customer array is full! Cannot insert new customer.\n";
        return;
    }

    Customer newCustomer;
    cout << "Enter Customer ID: ";
    cin >> newCustomer.id;
    cin.ignore();  // to clear the newline character from input buffer
    cout << "Enter Customer Name: ";
    getline(cin, newCustomer.name);
    cout << "Enter Customer Contact Number: ";
    getline(cin, newCustomer.contactNumber);
    cout << "Enter Customer Address: ";
    getline(cin, newCustomer.address);

    customers[count++] = newCustomer;
    cout << "Customer added successfully.\n";
}

// Function to update customer information
void updateCustomer(Customer customers[], int count) {
    if (count == 0) {
        cout << "No customers available to update.\n";
        return;
    }

    int id;
    cout << "Enter Customer ID to update: ";
    cin >> id;

    int index = findCustomerIndexById(customers, count, id);
    if (index == -1) {
        cout << "Customer not found!\n";
    } else {
        cin.ignore();  // to clear the newline character from input buffer
        cout << "Enter new name: ";
        getline(cin, customers[index].name);
        cout << "Enter new contact number: ";
        getline(cin, customers[index].contactNumber);
        cout << "Enter new address: ";
        getline(cin, customers[index].address);
        cout << "Customer updated successfully.\n";
    }
}

// Function to delete a customer
void deleteCustomer(Customer customers[], int &count) {
    if (count == 0) {
        cout << "No customers available to delete.\n";
        return;
    }

    int id;
    cout << "Enter Customer ID to delete: ";
    cin >> id;

    int index = findCustomerIndexById(customers, count, id);
    if (index == -1) {
        cout << "Customer not found!\n";
    } else {
        for (int i = index; i < count - 1; i++) {
            customers[i] = customers[i + 1];
        }
        count--;
        cout << "Customer deleted successfully.\n";
    }
}

// Function to find customer index by ID
int findCustomerIndexById(Customer customers[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            return i;
        }
    }
    return -1;  // Return -1 if customer not found
}
