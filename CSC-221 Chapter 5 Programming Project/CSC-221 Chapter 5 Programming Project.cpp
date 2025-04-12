// CSC-221 Chapter 5 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Write a program that reads a list of names from a file called LineUp.txt. The program should read the names and determine the first and last names in alphabetical order.
// It should also count the total number of names in the file. The program should display the total number of names, the first name in line, and the last name in line.
// LineUp.txt is located in the same directory as this program.
// <iostream>, <fstream>, <string> are included for input/output operations and string manipulation.
// ifstream, string, and cout are used for file input, string handling, and console output respectively.
// The program uses from here on out to read the file, process the names, and display the results.
// Each step is commented to explain its purpose.
// Returns 0 to indicate successful completion of the program.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");
    string name;
    string firstInLine, lastInLine;
    int count = 0;

    // Check and see if the file opened.
    if (!inputFile) {
        cout << "Error: Could not open the file LineUp.txt." << endl;
        return 1;
    }

    // Read the first name (if there is one).
    if (inputFile >> name) {
        firstInLine = name;
        lastInLine = name;
        count = 1;
    }

    // Read the rest of the names.
    while (inputFile >> name) {
        count++;

        if (name < firstInLine) {
            firstInLine = name;
        }

        if (name > lastInLine) {
            lastInLine = name;
        }
    }
	
    inputFile.close();
   
	// Display the results.
    if (count > 0) {
        cout << "Total number of students: " << count << endl;
        cout << "First in Line: " << firstInLine << endl;
        cout << "Last in Line: " << lastInLine << endl;
    }
    else {
        cout << "File is empty." << endl;
    }

    return 0;
}