#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    // Generate a random number between 1 and 1000
    int randomNumber = rand() % 1000 + 1;
    int userGuess = 0;

    cout << "***************************Welcome to the Number Guessing Game!*******************************" << endl; // Display a welcome message
    cout << "I have chosen a number between 1 and 1000. Can you guess it?" << endl; // Display a message asking the user to guess the number

    // Loop until the user guesses the correct number
    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < randomNumber) { 
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) { 
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl; // Correct number
            break;
        }
    }
    return 0;
}
