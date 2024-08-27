 #include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
#include <string>
#include <cmath>  // Include cmath for the pow function

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {//if character or input is alphanumeric  i.e letters it will be pushed to postfix string
            postfix += c;
        } else if (c == '(') {//if input is ( then push on stack
            s.push(c);
        } else if (c == ')') {//if input is ) then pop all elements from stack until( is encountered and discard (
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();  // Remove '(' from the stack
        } else if (isOperator(c)) {//if input is operator check precendence
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {//top of stack has highest precendence pop to string and then push in stack
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to convert postfix expression to prefix
string postfixToPrefix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isalnum(c)) {//if input is alphanumeric push in stack
            s.push(string(1, c));
        } else if (isOperator(c)) {//if input is operator
            string op1 = s.top();//pop two elements from top of stackand push in prefix string
            s.pop();
            string op2 = s.top();
            s.pop();
            string prefix = c + op2 + op1;//operator+A+B PREFIX
            s.push(prefix);//PUSH result in stack
        }
    }

    return s.top();
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {//if input is digit convert to interger and push to stack
            s.push(c - '0');  // Convert char to int
        } else if (isOperator(c)) {
            int op2 = s.top();//if input is operator  pop first two digits of stack 
            s.pop();
            int op1 = s.top();
            s.pop();
//an dperform the operations
            switch (c) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
                case '^':
                    s.push(pow(op1, op2));
                    break;
            }
        }
    }

    return s.top();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Postfix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> expression;
                cout << "Postfix expression: " << infixToPostfix(expression) << endl;
                break;

            case 2:
                cout << "Enter a postfix expression: ";
                cin >> expression;
                cout << "Prefix expression: " << postfixToPrefix(expression) << endl;
                break;

            case 3:
                cout << "Enter a postfix expression: ";
                cin >> expression;
                cout << "Evaluation result: " << evaluatePostfix(expression) << endl;
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
