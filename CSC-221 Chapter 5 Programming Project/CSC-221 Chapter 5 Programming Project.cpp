// CSC-221 Chapter 5 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Write a program that will predict the starting population of a species of organism.
// The program should ask the user for the starting number of organisms, the average daily population increase (as a percentage), and the number of days they will multiply. 
// A loop should be used to display the population for each day, starting with the initial population.
// <iostream>, <cmath>, and <iomanip> libraries are used for input/output, mathematical operations, and formatting respectively.
// int startpop, double dailyIncrease, and int days are declared to store user inputs.
// See below for each input validation and the loop to calculate and display the population for each day.
// Return 0 indicates successful completion of the program.

#include <iostream>
#include <cmath>     // For floor()
#include <iomanip>   // For setw()

using namespace std;

int main() {
    int startpop;
    double dailyIncrease;
    int days;

    // Get starting population with input validation
    cout << "Enter the starting number of organisms (minimum 2): ";
    cin >> startpop;
    while (startpop < 2) {
        cout << "Invalid input. The population must be at least 2. Try again: ";
        cin >> startpop;
    }

    // Get average daily population increase with input validation
    cout << "Enter the average daily population increase (as a percentage, non-negative): ";
    cin >> dailyIncrease;
    while (dailyIncrease < 0) {
        cout << "Invalid input. The increase must be non-negative. Try again: ";
        cin >> dailyIncrease;
    }

    // Get number of days with input validation
    cout << "Enter the number of days they will multiply (minimum 1): ";
    cin >> days;
    while (days < 1) {
        cout << "Invalid input. The number of days must be at least 1. Try again: ";
        cin >> days;
    }

    // Display population size starting with initial population
    int population = startpop;
    cout << "\n" << left << setw(10) << "Day" << setw(15) << "Population" << endl;
    cout << "--------------------------\n";
    cout << left << setw(10) << "Initial" << setw(15) << population << endl;

    for (int day = 1; day <= days; ++day) {
        population = static_cast<int>(floor(population + (population * (dailyIncrease / 100.0))));
        cout << left << setw(10) << day << setw(15) << population << endl;
    }

    return 0;
}
