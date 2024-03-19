#include <iostream>

using namespace std;

const int size = 3;

void displayBoard(char board[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[][3], char player) {
    for(int i = 0; i < size; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for(int j = 0; j < 3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;

}

bool isDraw(char board[][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}


int getPlayerInput(char board[][3]) {
    int row, col;
    while(true) {
        cout << "Enter row (1-3): ";
        cin >> row;

        cout << "Enter column (1-3): ";
        cin >> col;

        row--; 
        col--;

        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            return row * size + col; 
        } 
        else {
            cout << "Invalid move. Please try again." << endl;
        }
    }
}

int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';

    while(true) {
        displayBoard(board);

        int move = getPlayerInput(board);

        board[move / 3][move % 3] = currentPlayer;

        if(checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << currentPlayer << " wins!" << endl;
            break;
        }

        if(isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char choice;
    cout << "Play again? (y/n): ";
    cin >> choice;

    if(choice == 'y' || choice == 'Y') {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        currentPlayer = 'X';

    }

    return 0;


}
