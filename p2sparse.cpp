#include <iostream>
#include <vector>
using namespace std;

// Structure to represent an element in the sparse matrix
struct Element {
    int row;
    int col;
    int value;
};

// Class to represent a Sparse Matrix
class SparseMatrix {
private:
    int rows, cols;
    vector<Element> elements;  // Vector to store non-zero elements

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Function to add an element to the sparse matrix
    void addElement(int r, int c, int value) {
        if (value != 0) {
            elements.push_back({r, c, value});
        }
    }

    // Function to display the sparse matrix in triplet form
    void display() const {  // Marked as const
        cout << "Sparse Matrix (row, col, value):" << endl;
        for (const auto &el : elements) {
            cout << "(" << el.row << ", " << el.col << ", " << el.value << ")" << endl;
        }
    }

    // Function to transpose the sparse matrix
    SparseMatrix transpose() const {  // Marked as const
        SparseMatrix transposed(cols, rows);
        for (const auto &el : elements) {
            transposed.addElement(el.col, el.row, el.value);
        }
        return transposed;
    }

    // Function to add two sparse matrices
    SparseMatrix add(const SparseMatrix &other) const {  // Marked as const
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must be the same for addition.");
        }

        SparseMatrix result(rows, cols);
        int i = 0, j = 0;

        while (i < elements.size() && j < other.elements.size()) {
            if (elements[i].row < other.elements[j].row ||
               (elements[i].row == other.elements[j].row && elements[i].col < other.elements[j].col)) {
                result.elements.push_back(elements[i++]);
            } else if (elements[i].row > other.elements[j].row ||
                      (elements[i].row == other.elements[j].row && elements[i].col > other.elements[j].col)) {
                result.elements.push_back(other.elements[j++]);
            } else {
                int summedValue = elements[i].value + other.elements[j].value;
                if (summedValue != 0) {
                    result.elements.push_back({elements[i].row, elements[i].col, summedValue});
                }
                i++;
                j++;
            }
        }

        // Add remaining elements from both matrices
        while (i < elements.size()) result.elements.push_back(elements[i++]);
        while (j < other.elements.size()) result.elements.push_back(other.elements[j++]);

        return result;
    }

    // Function to multiply two sparse matrices
    SparseMatrix multiply(const SparseMatrix &other) const {  // Marked as const
        if (cols != other.rows) {
            throw invalid_argument("Number of columns of the first matrix must be equal to the number of rows of the second matrix for multiplication.");
        }

        SparseMatrix result(rows, other.cols);

        // Transpose the second matrix for easier column-wise access
        SparseMatrix transposedOther = other.transpose();

        for (const auto &elA : elements) {
            for (const auto &elB : transposedOther.elements) {
                if (elA.col == elB.row) {
                    int row = elA.row;
                    int col = elB.col;
                    int value = elA.value * elB.value;
                    // Check if there's already an element at this position in result
                    bool found = false;
                    for (auto &resEl : result.elements) {
                        if (resEl.row == row && resEl.col == col) {
                            resEl.value += value;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.addElement(row, col, value);
                    }
                }
            }
        }

        return result;
    }
};

// Utility function to create a sparse matrix from user input
SparseMatrix createSparseMatrix(int rows, int cols) {
    SparseMatrix matrix(rows, cols);
    cout << "Enter the number of non-zero elements: ";
    int nonZero;
    cin >> nonZero;

    for (int i = 0; i < nonZero; i++) {
        int r, c, value;
        cout << "Enter row, column, and value of element " << i + 1 << ": ";
        cin >> r >> c >> value;
        matrix.addElement(r, c, value);
    }
    return matrix;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input for first matrix
    cout << "Enter rows and columns for first sparse matrix: ";
    cin >> rows1 >> cols1;
    SparseMatrix matrix1 = createSparseMatrix(rows1, cols1);

    // Input for second matrix
    cout << "Enter rows and columns for second sparse matrix: ";
    cin >> rows2 >> cols2;
    SparseMatrix matrix2 = createSparseMatrix(rows2, cols2);

    cout << "\nFirst Matrix:\n";
    matrix1.display();

    cout << "\nSecond Matrix:\n";
    matrix2.display();

    // Perform operations
    try {
        // Addition
        cout << "\nAddition Result:\n";
        SparseMatrix sumMatrix = matrix1.add(matrix2);
        sumMatrix.display();

        // Multiplication
        cout << "\nMultiplication Result:\n";
        SparseMatrix productMatrix = matrix1.multiply(matrix2);
        productMatrix.display();

        // Transpose of first matrix
        cout << "\nTranspose of First Matrix:\n";
        SparseMatrix transposeMatrix1 = matrix1.transpose();
        transposeMatrix1.display();

        // Transpose of second matrix
        cout << "\nTranspose of Second Matrix:\n";
        SparseMatrix transposeMatrix2 = matrix2.transpose();
        transposeMatrix2.display();

    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
