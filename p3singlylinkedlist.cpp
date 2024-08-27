#include <iostream>
#include <string>
using namespace std;

// Node structure representing each student's information
struct Node {
    int rollNo;
    string name;
    string placementStatus;
    Node* next;//pointer to next node in list
};

// Singly Linked List class
class PlacementList {
private:
    Node* head;//pointer to the first node in the list

public:
    PlacementList() : head(nullptr) {}// constructor initializes the linked list with an empty list (i.e., head is set to nullptr).

    // Function to insert a new student at the end of the list
    void insertStudent(int rollNo, string name, string placementStatus) {
        Node* newNode = new Node{rollNo, name, placementStatus, nullptr};

        if (head == nullptr) {//if list is empty set new node as head of list
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;//else traverse the entire list until the last node is found and insert new node at end 
        }
        cout << "Student added successfully.\n";
    }

    // Function to update student information by roll number
    void updateStudent(int rollNo, string name, string placementStatus) {
        Node* temp = head;

        while (temp != nullptr) {// Traverse the list to find the student with the matching rollNo if foundupdate details
            if (temp->rollNo == rollNo) {
                temp->name = name;
                temp->placementStatus = placementStatus;
                cout << "Student record updated successfully.\n";
                return;
            }
            temp = temp->next;//If not found, print a message indicating the student was not found.
        }
        cout << "Student not found.\n";
    }

    // Function to search for a student by roll number
    void searchStudent(int rollNo) {
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->rollNo == rollNo) {
                cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name
                     << ", Placement Status: " << temp->placementStatus << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    // Function to sort the linked list by roll number
    void sortStudents() {
        if (head == nullptr) return;//If the list is empty, return immediately.

        Node* i = head;
        while (i != nullptr) {
            Node* j = i->next;
            while (j != nullptr) {
                if (i->rollNo > j->rollNo) {
                    swap(i->rollNo, j->rollNo);
                    swap(i->name, j->name);
                    swap(i->placementStatus, j->placementStatus);
                }
                j = j->next;
            }
            i = i->next;
        }
        cout << "Students sorted by roll number.\n";
    }

    // Function to list all students
    void listStudents() {
        if (head == nullptr) {//empty list
            cout << "No students in the list.\n";
            return;
        }

        Node* temp = head;
        cout << "Student List:\n";
        while (temp != nullptr) {
            cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name
                 << ", Placement Status: " << temp->placementStatus << "\n";
            temp = temp->next;// Traverse the list and print the details of each student.
        }
    }

    // Function to delete a student by roll number
    void deleteStudent(int rollNo) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->rollNo == rollNo) {//If the student to be deleted is the first node (head), update head to point to the next node and delete the current head.cpp

            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Student deleted successfully.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->rollNo != rollNo) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found.\n";
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Student deleted successfully.\n";
        }
    }
};

int main() {
    PlacementList placementList;
    int choice, rollNo;
    string name, placementStatus;

    do {
        cout << "\nPlacement Information System\n";
        cout << "1. Insert Student\n";
        cout << "2. Update Student\n";
        cout << "3. Search Student\n";
        cout << "4. Sort Students\n";
        cout << "5. List Students\n";
        cout << "6. Delete Student\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll No: ";
            cin >> rollNo;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Placement Status: ";
            getline(cin, placementStatus);
            placementList.insertStudent(rollNo, name, placementStatus);
            break;

        case 2:
            cout << "Enter Roll No of student to update: ";
            cin >> rollNo;
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Placement Status: ";
            getline(cin, placementStatus);
            placementList.updateStudent(rollNo, name, placementStatus);
            break;

        case 3:
            cout << "Enter Roll No to search: ";
            cin >> rollNo;
            placementList.searchStudent(rollNo);
            break;

        case 4:
            placementList.sortStudents();
            break;

        case 5:
            placementList.listStudents();
            break;

        case 6:
            cout << "Enter Roll No of student to delete: ";
            cin >> rollNo;
            placementList.deleteStudent(rollNo);
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
