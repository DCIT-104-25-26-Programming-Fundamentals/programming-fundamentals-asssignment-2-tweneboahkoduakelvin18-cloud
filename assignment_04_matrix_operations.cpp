// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Read a matrix
void readMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Display a matrix
void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(int matrix[][10], int transpose[][10],
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(int matrix1[][10], int matrix2[][10],
                 int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(int matrixA[][10], int matrixB[][10],
                      int result[][10],
                      int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;

            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int choice;

    cout << "MATRIX OPERATIONS" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int matrix[10][10];
        int transpose[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        readMatrix(matrix, rows, cols);

        transposeMatrix(matrix, transpose, rows, cols);

        cout << "\nOriginal Matrix:\n";
        displayMatrix(matrix, rows, cols);

        cout << "\nTransposed Matrix:\n";
        displayMatrix(transpose, cols, rows);
    }

    else if (choice == 2) {
        int rows, cols;
        int matrix1[10][10];
        int matrix2[10][10];
        int sum[10][10];

        cout << "Enter number of rows: ";
        cin >> rows;

        cout << "Enter number of columns: ";
        cin >> cols;

        if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        cout << "\nEnter Matrix 1:\n";
        readMatrix(matrix1, rows, cols);

        cout << "\nEnter Matrix 2:\n";
        readMatrix(matrix2, rows, cols);

        addMatrices(matrix1, matrix2, sum, rows, cols);

        cout << "\nResult of Addition:\n";
        displayMatrix(sum, rows, cols);
    }

    else if (choice == 3) {
        int rowsA, colsA, rowsB, colsB;
        int matrixA[10][10];
        int matrixB[10][10];
        int product[10][10];

        cout << "Enter rows of Matrix A: ";
        cin >> rowsA;

        cout << "Enter columns of Matrix A: ";
        cin >> colsA;

        cout << "Enter rows of Matrix B: ";
        cin >> rowsB;

        cout << "Enter columns of Matrix B: ";
        cin >> colsB;

        if (rowsA <= 0 || rowsA > 10 || colsA <= 0 || colsA > 10 ||
            rowsB <= 0 || rowsB > 10 || colsB <= 0 || colsB > 10) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        if (colsA != rowsB) {
            cout << "Error: Matrix multiplication not possible." << endl;
            return 1;
        }

        cout << "\nEnter Matrix A:\n";
        readMatrix(matrixA, rowsA, colsA);

        cout << "\nEnter Matrix B:\n";
        readMatrix(matrixB, rowsB, colsB);

        multiplyMatrices(matrixA, matrixB, product,
                         rowsA, colsA, colsB);

        cout << "\nProduct Matrix:\n";
        displayMatrix(product, rowsA, colsB);
    }

    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}