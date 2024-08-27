#include <iostream>
#include <string>
#define MAX 5
using namespace std;

// Node structure for Linked List (used in Linear Queue)
struct Node {
    string order;
    Node* next;
};

// Linear Queue using Linked List
class LinearQueue {
private:
    Node* front;
    Node* rear;
public:
    LinearQueue() {
        front = rear = nullptr;
    }

    void enqueue(string order) {//create a new node and assign orders to it 
        Node* newNode = new Node();
        newNode->order = order;
        newNode->next = nullptr;

        if (rear == nullptr) {// if queue is empty then front and rear will point to newnode
            front = rear = newNode;
        } else {//else add new node to end of list and update rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Order " << order << " added to the Linear Queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Linear Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Order " << front->order << " served from the Linear Queue.\n";
        front = front->next;//update front to next node in list

        if (front == nullptr) {//If the queue becomes empty after dequeueing, sets rear to nullptr.

            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Linear Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Current Orders in Linear Queue: ";
        while (temp != nullptr) {
            cout << temp->order << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};//Traverses the list from front to rear, printing each order.

// Circular Queue using Array
class CircularQueue {
private:
    string orders[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(string order) {
        if ((rear + 1) % MAX == front) {
            cout << "Circular Queue is full.\n";
            return;
        }

        if (front == -1) {  // Queue is empty
            front = 0;
        }
        rear = (rear + 1) % MAX;
        orders[rear] = order;//store order in rear position in array
        cout << "Order " << order << " added to the Circular Queue.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Circular Queue is empty.\n";
            return;
        }
        cout << "Order " << orders[front] << " served from the Circular Queue.\n";

        if (front == rear) {  // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Circular Queue is empty.\n";
            return;
        }
        cout << "Current Orders in Circular Queue: ";
        int i = front;
        while (true) {
            cout << orders[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

// Main Program: Menu-Driven
int main() {
    LinearQueue linearQueue;
    CircularQueue circularQueue;
    int choice, queueType;
    string order;

    do {
        cout << "\n--- Food Ordering System ---\n";
        cout << "Select Queue Type:\n";
        cout << "1. Linear Queue (Linked List)\n";
        cout << "2. Circular Queue (Array)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> queueType;

        if (queueType == 3) {
            cout << "Exiting...\n";
            break;
        }

        if (queueType != 1 && queueType != 2) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        do {
            cout << "\n--- Operations Menu ---\n";
            cout << "1. Add Order (Enqueue)\n";
            cout << "2. Serve Order (Dequeue)\n";
            cout << "3. Display Orders\n";
            cout << "4. Back to Queue Selection\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter food order: ";
                cin >> order;
                if (queueType == 1) {
                    linearQueue.enqueue(order);
                } else if (queueType == 2) {
                    circularQueue.enqueue(order);
                }
                break;
            case 2:
                if (queueType == 1) {
                    linearQueue.dequeue();
                } else if (queueType == 2) {
                    circularQueue.dequeue();
                }
                break;
            case 3:
                if (queueType == 1) {
                    linearQueue.display();
                } else if (queueType == 2) {
                    circularQueue.display();
                }
                break;
            case 4:
                cout << "Returning to Queue Selection...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);

    } while (queueType != 3);

    return 0;
}
