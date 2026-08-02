// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================

    
#include <iostream>
#include <vector>
using namespace std;
// Function to calculate the sum
double calculateSum(const std::vector<double>& numbers) {
    double total = 0;
    for (double num : numbers) {
        total += num;
    }
    return total;
}

// Function to calculate the average
double calculateAverage(const std::vector<double>& numbers) {
    double total = calculateSum(numbers);
    return total / numbers.size();
}

// Function to find the maximum value
double findMaximum(const std::vector<double>& numbers) {
    double maximum = numbers[0];
    for (double num : numbers) {
        if (num > maximum) {
            maximum = num;
        }
    }
    return maximum;
}

// Function to find the minimum value
double findMinimum(const std::vector<double>& numbers) {
    double minimum = numbers[0];
    for (double num : numbers) {
        if (num < minimum) {
            minimum = num;
        }
    }
    return minimum;
}

// Main program
int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    if (cin.fail()|| cin.peek() != '\n' ) {
        cout << "Error: Please enter a valid integer." << endl;
        return 1;
    }

    if (n <= 0) {
        cout << "Error: Number of values must be positive." << endl;
        return 1;
    }

    vector<double> numbers;

    for (int i = 0; i < n; i++) {
        double num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        numbers.push_back(num);
    }

    double total = calculateSum(numbers);
    double average = calculateAverage(numbers);
    double maximum = findMaximum(numbers);
    double minimum = findMinimum(numbers);

    cout << "\nResults:" << endl;
    cout << "Sum:     " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;

    return 0;
}

// =============================================================================