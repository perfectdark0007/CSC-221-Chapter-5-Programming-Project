// CSC-221 Chapter 5 Programming Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Write a program that generates a random number between 1 and 100 (for example). The user should be prompted to guess the number. 
// If the user guesses too high or too low, the program should inform them of that. The program should continue to prompt the user for guesses until they guess the correct number. 
// Once the user guesses the correct number, the program should display how many guesses it took to get the correct answer.
// <iostream>, <cstdlib>, <ctime> are included for input/output, random number generation, and time functions respectively.
// The program uses the standard namespace to avoid prefixing standard library functions with "std::".
// Each step is commented to explain its purpose.
// rand() is used to generate a random number, and srand() seeds the random number generator with the current time to ensure different results each run.


#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    int guessCount = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100." << endl;
    cout << "Try to guess what it is!" << endl;

    // Loop until the user guesses the correct number
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        guessCount++;  // Increment the guess count

        if (userGuess > randomNumber) {
            cout << "Too high, try again." << endl;
        }
        else if (userGuess < randomNumber) {
            cout << "Too low, try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the number." << endl;
            cout << "It took you " << guessCount << " guesses." << endl;
        }

    } while (userGuess != randomNumber);  // Repeat until the guess is correct

    return 0;
}