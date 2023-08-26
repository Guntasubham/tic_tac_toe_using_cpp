#include <iostream>

const int BOARD_SIZE = 3;

// Function to display the Tic Tac Toe board
void displayBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[][BOARD_SIZE], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }
    return false;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int totalMoves = BOARD_SIZE * BOARD_SIZE;
    char currentPlayer = 'X';

    std::cout << "welcome to Tic Tac Toe Game\n";
    displayBoard(board);

    for (int move = 0; move < totalMoves; ++move) {
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter row and column: ";
        std::cin >> row >> col;

        if (row < 1 || row > BOARD_SIZE || col < 1 || col > BOARD_SIZE || board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O') {
            std::cout << "Invalid move. Try again.\n";
            --move;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            std::cout << "congratulations Player " << currentPlayer << " wins!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!checkWin(board, 'X') && !checkWin(board, 'O')) {
        std::cout << "It's a draw!\n";
    }

    return 0;
}