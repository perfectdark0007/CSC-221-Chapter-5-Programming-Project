// CSC-221 Chapter 5 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Write a program that produces a bar graph of the population growth of a city/town. The program should be able to read the data from a file of any name.
// <iostream>, <fstream>, and <string> are included to handle input and output operations.
// namespaces are used to avoid prefixing standard library functions with "std::".
// Each step is commented to explain its purpose.
// Return 0 indicates successful completion of the program.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string townName, fileName;

    // Get town name from user
    cout << "Enter the name of the city/town: ";
    getline(cin, townName);

    // Get file name from user
    cout << "Enter the name of the data file: ";
    getline(cin, fileName);

    // Add .txt if not included in the filename
    if (fileName.find(".txt") == string::npos) {
        fileName += ".txt";
    }

    // Open file
    ifstream inputFile(fileName);
    if (!inputFile) {
        cerr << "Error: Could not open the file \"" << fileName << "\"." << endl;
        return 1;
    }

    // Print title
    cout << endl;
    cout << townName << " Population Growth" << endl;
    cout << "(each * represents 1,000 people)" << endl;

    int year, population;
    while (inputFile >> year >> population) {
        cout << year << " ";
        int stars = max(1, population / 1000); // safer for small population
        for (int i = 0; i < stars; ++i) {
            cout << "*";
        }
        cout << endl;
    }

    inputFile.close();
    return 0;
}

