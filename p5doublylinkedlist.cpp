#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insert(int data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to sort the list using bubble sort
    void sort() {
        if (head == nullptr) return;

        bool swapped;
        Node* temp;

        do {
            swapped = false;
            temp = head;

            while (temp->next != nullptr) {
                if (temp->data > temp->next->data) {
                    swap(temp->data, temp->next->data);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }

    // Function to merge two sorted lists
    void merge(DoublyLinkedList& other) {
        Node* temp1 = head;
        Node* temp2 = other.head;

        while (temp2 != nullptr) {
            insert(temp2->data);
            temp2 = temp2->next;
        }

        // Sort the merged list
        sort();
    }

    // Function to display the list
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list1, list2;

    int n, mark;

    // Input for the first list of marks
    cout << "Enter the number of marks for the first list: ";
    cin >> n;
    cout << "Enter the marks for the first list:\n";
    for (int i = 0; i < n; i++) {
        cin >> mark;
        list1.insert(mark);
    }

    // Input for the second list of marks
    cout << "Enter the number of marks for the second list: ";
    cin >> n;
    cout << "Enter the marks for the second list:\n";
    for (int i = 0; i < n; i++) {
        cin >> mark;
        list2.insert(mark);
    }

    // Sort both lists
    list1.sort();
    list2.sort();

    // Display sorted lists
    cout << "\nSorted first list: ";
    list1.display();

    cout << "Sorted second list: ";
    list2.display();

    // Merge the two lists
    list1.merge(list2);

    // Display the merged list
    cout << "\nMerged and sorted list: ";
    list1.display();

    return 0;
}
