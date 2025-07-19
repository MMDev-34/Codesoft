#include <iostream>
using namespace std;

char board[3][3]; // 3x3 board
char currentPlayer = 'X';

void initializeBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

bool isWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    for (int j = 0; j < 3; j++)
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

bool makeMove(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (cell < 1 || cell > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    } else {
        board[row][col] = currentPlayer;
        return true;
    }
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int move;
    bool valid;

    initializeBoard();
    currentPlayer = 'X';

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        valid = makeMove(move);
        if (!valid) {
            cout << "❌ Invalid move! Try again.\n";
            continue;
        }

        if (isWin()) {
            displayBoard();
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "🤝 It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char again;

    do {
        cout << "\n🎮 Welcome to Tic-Tac-Toe Game!\n";
        playGame();

        cout << "\n🔁 Do you want to play again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "👋 Thanks for playing. Goodbye!\n";
    return 0;
