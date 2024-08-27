#include <iostream>
#include <string>
using namespace std;

// Recursive function to generate all combinations of a given string
void generateCombinations(string input, string output, int index) {
    // Base case: If we've considered all characters
    if (index == input.length()) {
        if (!output.empty()) {
            cout << output << endl;
        }
        return;
    }

    // Exclude the current character and proceed to the next
    generateCombinations(input, output, index + 1);

    // Include the current character in the combination and proceed to the next
    generateCombinations(input, output + input[index], index + 1);
}

int main() {
    string input;

    // Taking user input for the string
    cout << "Enter a string: ";
    cin >> input;

    cout << "All possible combinations of the string are:\n";
    generateCombinations(input, "", 0);

    return 0;
}
