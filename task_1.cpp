#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;

    int guess;
    bool isGuessed = false;

    while(!isGuessed) {
        cout << "Guess the number between 1 to 100 : ";
        cin >> guess;

        if(guess == secretNumber) {
            cout << "Congratulations! You guessed the right number!" << endl;
            isGuessed = true;
        } 

        else if(guess < secretNumber) {
            cout << "Your guess is smaller. Try again." << endl;
        } 

        else    cout << "Your guess is bigger. Try again." << endl;
        
    }

    return 0;

}
