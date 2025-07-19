#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to select difficulty level and return max number
int chooseDifficulty() {
    int choice;
    cout << "\nSelect Difficulty Level:" << endl;
    cout << "1. Easy (1 - 50)" << endl;
    cout << "2. Medium (1 - 100)" << endl;
    cout << "3. Hard (1 - 200)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch(choice) {
        case 1: return 50;
        case 2: return 100;
        case 3: return 200;
        default:
            cout << "Invalid choice. Defaulting to Medium." << endl;
            return 100;
    }
}

int main() {
    srand(time(0)); // Initialize random seed
    char playAgain;

    do {
        int maxNumber = chooseDifficulty();
        int secretNumber = rand() % maxNumber + 1;
        int userGuess;
        int attempts = 0;

        cout << "\n🎯 I'm thinking of a number between 1 and " << maxNumber << "." << endl;

        // Game loop
        do {
            cout << "Enter your guess: ";
            cin >> userGuess;
            attempts++;

            if (userGuess > secretNumber) {
                cout << "📉 Too high! Try again." << endl;
            } else if (userGuess < secretNumber) {
                cout << "📈 Too low! Try again." << endl;
            } else {
                cout << "🎉 Correct! You guessed the number in " << attempts << " attempts." << endl;
                if (attempts <= 5) {
                    cout << "🏆 Excellent!" << endl;
                } else if (attempts <= 10) {
                    cout << "👍 Good job!" << endl;
                } else {
                    cout << "👏 You got it, but you can do better!" << endl;
                }
            }

        } while (userGuess != secretNumber);

        // Ask to play again
        cout << "\n🔁 Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "👋 Thanks for playing! Goodbye!" << endl;
    return 0;
}
