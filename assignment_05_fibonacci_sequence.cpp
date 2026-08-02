// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
#include <iostream>
using namespace std;
// PART A: Print the first N Fibonacci terms
void printFibonacci(int n) {
    int first = 0, second = 1, next;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++) {
        cout << first << " ";

        next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

// PART B: Check if a number is a Fibonacci number
void checkFibonacci(int num) {
    if (num < 0) {
        cout << "Error: Fibonacci numbers cannot be negative." << endl;
        return;
    }

    int first = 0, second = 1, next;

    while (first < num) {
        next = first + second;
        first = second;
        second = next;
    }

    if (first == num) {
        cout << num << " is a Fibonacci number." << endl;
    }
    else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    string input;
    int n, num;

    cout << "How many terms? ";
    cin >> input;

    // Check for wrong input and floats
    try {
        n = stoi(input);

        if (input.find('.') != string::npos) {
            cout << "Error: Please enter a valid integer, not a decimal." << endl;
            return 1;
        }
    }
    catch (...) {
        cout << "Error: Please enter a valid integer." << endl;
        return 1;
    }

    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return 1;
    }

    printFibonacci(n);


    cout << "\nEnter a number to check: ";
    cin >> input;

    // Check for wrong input and floats
    try {
        num = stoi(input);

        if (input.find('.') != string::npos) {
            cout << "Error: Please enter a valid integer, not a decimal." << endl;
            return 1;
        }
    }
    catch (...) {
        cout << "Error: Please enter a valid integer." << endl;
        return 1;
    }

    checkFibonacci(num);

    return 0;
}

// =============================================================================

