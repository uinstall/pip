#include <iostream>
#include <vector>
using namespace std;

// Function to perform Fibonacci Search
int fibonacciSearch(vector<int>& arr, int x, int n) {
    int fib2 = 0; // (m-2)'th Fibonacci number
    int fib1 = 1; // (m-1)'th Fibonacci number
    int fibM = fib1 + fib2; // m'th Fibonacci number

    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    return -1;
}

// Function to perform Binary Search
int binarySearch(vector<int>& arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Function to perform Sentinel Search
int sentinelSearch(vector<int>& arr, int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) {
        return i;
    }
    return -1;
}

// Function to display the array
void displayArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, choice, searchKey;

    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> marks(n);
    cout << "Enter the marks of each student:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Fibonacci Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Sentinel Search\n";
        cout << "4. Display Marks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the mark to search using Fibonacci Search: ";
                cin >> searchKey;
                {
                    int index = fibonacciSearch(marks, searchKey, n);
                    if (index != -1) {
                        cout << "Mark found at index " << index << " using Fibonacci Search.\n";
                    } else {
                        cout << "Mark not found using Fibonacci Search.\n";
                    }
                }
                break;

            case 2:
                cout << "Enter the mark to search using Binary Search: ";
                cin >> searchKey;
                {
                    int index = binarySearch(marks, 0, n - 1, searchKey);
                    if (index != -1) {
                        cout << "Mark found at index " << index << " using Binary Search.\n";
                    } else {
                        cout << "Mark not found using Binary Search.\n";
                    }
                }
                break;

            case 3:
                cout << "Enter the mark to search using Sentinel Search: ";
                cin >> searchKey;
                {
                    int index = sentinelSearch(marks, n, searchKey);
                    if (index != -1) {
                        cout << "Mark found at index " << index << " using Sentinel Search.\n";
                    } else {
                        cout << "Mark not found using Sentinel Search.\n";
                    }
                }
                break;

            case 4:
                cout << "Marks data: ";
                displayArray(marks);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
