#include <iostream>
using namespace std;

// Global 3x3 board
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

// Current player (X or O)
char currentPlayer = 'X';

// Function to display the board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if the game is won
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || // Rows
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) { // Columns
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || // Main diagonal
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) { // Anti-diagonal
        return true;
    }

    return false;
}

// Function to check if the board is full
bool checkTie() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // Empty spot found
            }
        }
    }
    return true; // No empty spots
}

// Function to handle a player's move
void makeMove() {
    int move;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> move;

    // Convert 1-9 input to 2D board indices
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    // Check if the move is valid
    if (move >= 1 && move <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
    } else {
        cout << "Invalid move. Try again.\n";
        makeMove();
    }
}

// Function to switch between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    cout << "*******************Welcome to Tic Tac Toe!88888888888888888888888\n";
    displayBoard();

    while (true) {
        makeMove();
        displayBoard();

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!!!!!! Congratulations!!!!!!!!\n";
            break;
        }

        if (checkTie()) {
            cout << "It's a tie!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}
