// CSC-221 Chapter 5 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Write a program that uses a loop to display Pattern A below, followed by another loop to display Pattern B.
// <iostream> and <iomanip> libraries are used to format the output.
// namespace std is used to avoid prefixing standard library functions with std::.
// const int rows = 10; defines the number of rows for the patterns.
// Each step is commented to explain the details of the code.


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int rows = 10;

    cout << left << setw(30) << "Pattern A" << "Pattern B" << endl;

    for (int i = 1; i <= rows; i++) {
        // Pattern A: increasing +
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }

        // Space to move Pattern B to the far right (fixed width for A)
        cout << setw(30 - i) << "";  // adjust total width to keep the align Pattern B neat

        // Pattern B: decreasing +
        int numPluses = rows - i + 1;
        for (int j = 0; j < numPluses; j++) {
            cout << "+";
        }

        cout << endl;
    }

    return 0;
}