#include <iostream>
using namespace std;

#define MAX 5  // Define maximum size for the deque

class Deque {
private:
    int arr[MAX];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    // Check if the deque is full
    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Insert element at the front
    void insertFront(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front.\n";
            return;
        }

        // Initial condition
        if (front == -1) {
            front = rear = 0;
        } 
        // Wrap around condition
        else if (front == 0) {
            front = MAX - 1;
        } 
        else {
            front--;
        }

        arr[front] = item;
        cout << "Inserted " << item << " at the front.\n";
    }

    // Insert element at the rear
    void insertRear(int item) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear.\n";
            return;
        }

        // Initial condition
        if (front == -1) {
            front = rear = 0;
        } 
        // Wrap around condition
        else if (rear == MAX - 1) {
            rear = 0;
        } 
        else {
            rear++;
        }

        arr[rear] = item;
        cout << "Inserted " << item << " at the rear.\n";
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }

        cout << "Deleted " << arr[front] << " from the front.\n";

        // Single element condition
        if (front == rear) {
            front = rear = -1;
        } 
        // Wrap around condition
        else if (front == MAX - 1) {
            front = 0;
        } 
        else {
            front++;
        }
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear.\n";

        // Single element condition
        if (front == rear) {
            front = rear = -1;
        } 
        // Wrap around condition
        else if (rear == 0) {
            rear = MAX - 1;
        } 
        else {
            rear--;
        }
    }

    // Display the deque
    void displayDeque() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Elements in the Deque are: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Deque dq;
    int choice, item;

    do {
        cout << "\nDeque Menu:\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to insert at front: ";
                cin >> item;
                dq.insertFront(item);
                break;
            case 2:
                cout << "Enter the item to insert at rear: ";
                cin >> item;
                dq.insertRear(item);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.displayDeque();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
