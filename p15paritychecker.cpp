#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Function to check the parity of a given binary number
string checkParity(int asciiValue) {
    // Convert ASCII value to binary using bitset (8 bits for 1 byte)
    bitset<8> binary(asciiValue);

    // Count the number of 1's in the binary representation
    int countOnes = binary.count();

    // Return "Even" if the number of 1's is even, otherwise return "Odd"
    if (countOnes % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}

int main() {
    string word;

    // Input a word from the user
    cout << "Enter a word: ";
    cin >> word;

    cout << "\nCharacter\tASCII Value\tBinary\t\tParity\n";
    cout << "--------------------------------------------------------\n";

    // Process each character in the word
    for (char c : word) {
        int asciiValue = static_cast<int>(c); // Get the ASCII value of the character
        bitset<8> binary(asciiValue);         // Convert ASCII value to binary

        // Check parity
        string parity = checkParity(asciiValue);

        // Display the character, ASCII value, binary representation, and parity
        cout << c << "\t\t" << asciiValue << "\t\t" << binary << "\t" << parity << endl;
    }

    return 0;
}
