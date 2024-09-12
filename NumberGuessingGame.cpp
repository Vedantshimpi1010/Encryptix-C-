#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

int main() {
    
    srand(time(0));

   
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it!" << endl;

    
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
