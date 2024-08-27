#include <iostream>
using namespace std;

int main() {
    int football, basketball, cricket;
    int football_basketball, football_cricket, basketball_cricket;
    int all_three;

    // Input the number of students participating in each sport
    cout << "Enter the number of students who play Football: ";
    cin >> football;
    cout << "Enter the number of students who play Basketball: ";
    cin >> basketball;
    cout << "Enter the number of students who play Cricket: ";
    cin >> cricket;

    // Input the number of students participating in two sports
    cout << "Enter the number of students who play both Football and Basketball: ";
    cin >> football_basketball;
    cout << "Enter the number of students who play both Football and Cricket: ";
    cin >> football_cricket;
    cout << "Enter the number of students who play both Basketball and Cricket: ";
    cin >> basketball_cricket;

    // Input the number of students participating in all three sports
    cout << "Enter the number of students who play all three sports (Football, Basketball, and Cricket): ";
    cin >> all_three;

    // Apply the Principle of Inclusion and Exclusion
    int total_unique = football + basketball + cricket 
                       - football_basketball - football_cricket - basketball_cricket 
                       + all_three;

    cout << "\nTotal number of unique students who participate in at least one sport: " << total_unique << endl;

    return 0;
}
