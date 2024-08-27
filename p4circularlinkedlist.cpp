#include <iostream>
using namespace std;

// Node structure representing a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    Node* next;
};

// Circular Linked List class for polynomial operations
class Polynomial {
private:
    Node* last;  // Pointer to the last node in the circular linked list

public:
    // Constructor
    Polynomial() : last(nullptr) {}

    // Function to insert a new term into the polynomial
    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node{coefficient, exponent, nullptr};

        if (last == nullptr) {//if list is empty
            last = newNode;// newnode becomes only node
            last->next = last;  // and next pounter points to itself forming Circular link
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }//else new node inserted at end of list
    }

    // Function to display the polynomial
    void display() const {
        if (last == nullptr) {
            cout << "Polynomial is empty.\n";
            return;
        }

        Node* temp = last->next;
        do {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp != last->next) {
                cout << " + ";
            }
        } while (temp != last->next);
        cout << endl;
    }

    // Function to add two polynomials
    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        Node* p1 = last ? last->next : nullptr;
        Node* p2 = other.last ? other.last->next : nullptr;

        if (!p1 || !p2) return result;  // If either polynomial is empty, return an empty result

        do {
            if (p1->exponent == p2->exponent) {
                int sumCoeff = p1->coefficient + p2->coefficient;
                if (sumCoeff != 0) {
                    result.insertTerm(sumCoeff, p1->exponent);
                }
                p1 = (p1 == last) ? nullptr : p1->next;
                p2 = (p2 == other.last) ? nullptr : p2->next;
            } else if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = (p1 == last) ? nullptr : p1->next;
            } else {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = (p2 == other.last) ? nullptr : p2->next;
            }
        } while (p1 || p2);

        return result;
    }

    // Function to multiply two polynomials
    Polynomial multiply(const Polynomial& other) const {
        Polynomial result;
        Node* p1 = last ? last->next : nullptr;

        if (!p1) return result;  // If the first polynomial is empty, return an empty result

        do {
            Node* p2 = other.last ? other.last->next : nullptr;
            do {
                int prodCoeff = p1->coefficient * p2->coefficient;
                int sumExp = p1->exponent + p2->exponent;
                result.addTermToResult(prodCoeff, sumExp);
                p2 = (p2 == other.last) ? nullptr : p2->next;
            } while (p2);
            p1 = (p1 == last) ? nullptr : p1->next;
        } while (p1);

        return result;
    }

    // Utility function to add a term to the result polynomial (used in multiplication)
    void addTermToResult(int coefficient, int exponent) {
        if (!last) {
            insertTerm(coefficient, exponent);
        } else {
            Node* temp = last->next;
            Node* prev = last;

            do {
                if (temp->exponent == exponent) {
                    temp->coefficient += coefficient;
                    return;
                }
                if (temp->exponent < exponent) {
                    Node* newNode = new Node{coefficient, exponent, temp};
                    prev->next = newNode;
                    if (temp == last->next) {
                        last = newNode;  // Update last pointer
                    }
                    return;
                }
                prev = temp;
                temp = temp->next;
            } while (temp != last->next);

            insertTerm(coefficient, exponent);
        }
    }
};

int main() {
    Polynomial poly1, poly2;
    int n, coefficient, exponent;

    // Input for the first polynomial
    cout << "Enter the number of terms for the first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        cin >> coefficient >> exponent;
        poly1.insertTerm(coefficient, exponent);
    }

    // Input for the second polynomial
    cout << "Enter the number of terms for the second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent for term " << i + 1 << ": ";
        cin >> coefficient >> exponent;
        poly2.insertTerm(coefficient, exponent);
    }

    cout << "\nFirst Polynomial: ";
    poly1.display();

    cout << "Second Polynomial: ";
    poly2.display();

    // Perform addition
    Polynomial sum = poly1.add(poly2);
    cout << "\nSum of Polynomials: ";
    sum.display();

    // Perform multiplication
    Polynomial product = poly1.multiply(poly2);
    cout << "Product of Polynomials: ";
    product.display();

    return 0;
}
