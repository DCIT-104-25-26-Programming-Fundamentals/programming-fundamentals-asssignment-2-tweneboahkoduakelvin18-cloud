// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
// Function to validate positive integers only
bool isValidPositiveInteger(double num)
{
    return (num > 0 && num == static_cast<int>(num));
}

// Part A: Print multiplication table for a single number
void singleTable(int num)
{
    cout << "\nMultiplication Table for " << num << ":\n";

    for (int i = 1; i <= 12; i++)
    {
        cout << num << " x " << i << " = " << num * i << endl;
    }
}

// Part B: Print multiplication tables from 1 to N
void tablesFromOneToN(int N)
{
    for (int num = 1; num <= N; num++)
    {
        cout << "\nMultiplication Table for " << num << ":\n";

        for (int i = 1; i <= 12; i++)
        {
            cout << num << " x " << i << " = " << num * i << endl;
        }

        cout << "---------------------------" << endl;
    }
}

int main()
{
    double input;
    int number, N;

    // Part A
    cout << "PART A - Single Multiplication Table" << endl;
    cout << "Enter a positive integer: ";
    cin >> input;

    if (!isValidPositiveInteger(input))
    {
        cout << "Error: Input must be a positive integer." << endl;
        return 0;
    }

    number = static_cast<int>(input);
    singleTable(number);

    // Part B
    cout << "\nPART B - Tables from 1 to N" << endl;
    cout << "Enter a positive integer N: ";
    cin >> input;

    if (!isValidPositiveInteger(input))
    {
        cout << "Error: Input must be a positive integer." <<endl;
        return 0;
    }

    N = static_cast<int>(input);
    tablesFromOneToN(N);

    return 0;
}