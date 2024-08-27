#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate loan balance using linear recurrence relation
double calculateLoanBalance(double principal, double monthlyRate, double monthlyPayment, int months) {
    // Base case: If no more months left, return 0
    if (months == 0) {
        return principal;
    }

    // Recurrence relation: B_n = B_(n-1) * (1 + monthlyRate) - monthlyPayment
    double previousBalance = calculateLoanBalance(principal, monthlyRate, monthlyPayment, months - 1);
    double currentBalance = previousBalance * (1 + monthlyRate) - monthlyPayment;

    // If balance is close to zero, round to zero (loan is paid off)
    if (currentBalance < 0) {
        currentBalance = 0;
    }

    return currentBalance;
}

int main() {
    double principal, annualInterestRate, monthlyPayment;
    int years;

    // Input loan details
    cout << "Enter the loan amount (principal): ";
    cin >> principal;
    cout << "Enter the annual interest rate (in %): ";
    cin >> annualInterestRate;
    cout << "Enter the loan duration (in years): ";
    cin >> years;
    cout << "Enter the fixed monthly payment: ";
    cin >> monthlyPayment;

    // Calculate the monthly interest rate
    double monthlyRate = (annualInterestRate / 100) / 12;

    // Calculate the total number of months
    int totalMonths = years * 12;

    // Display the loan balance for each month
    cout << "\nMonth\tBalance\n";
    cout << "---------------------\n";
    for (int month = 0; month <= totalMonths; ++month) {
        double balance = calculateLoanBalance(principal, monthlyRate, monthlyPayment, month);
        cout << month << "\t" << balance << endl;
        
        // If balance is zero, break the loop
        if (balance == 0) {
            break;
        }
    }

    return 0;
}
