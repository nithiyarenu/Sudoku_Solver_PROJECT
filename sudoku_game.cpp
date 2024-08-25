#include<iostream>
#include<math.h>
using namespace std;

void print(int board[][9], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isvalid(int board[][9], int i, int j, int num, int n) {
    // Row check
    for (int x = 0; x < n; x++) {
        if (board[i][x] == num) {
            return false;
        }
    }
    // Column check
    for (int x = 0; x < n; x++) {
        if (board[x][j] == num) {
            return false;
        }
    }

    // Submatrix check
    int rn = sqrt(n);
    int si = i - i % rn;
    int sj = j - j % rn;
    for (int x = si; x < si + rn; x++) {
        for (int y = sj; y < sj + rn; y++) {
            if (board[x][y] == num) {
                return false;
            }
        }
    }
    return true;
}

bool sudokusolver(int board[][9], int i, int j, int n) {
    // Base case
    if (i == n) { // i==9 next line not there
        print(board, n);
        return true;
    }
    // If we are outside board after j=8
    if (j == n) {
        return sudokusolver(board, i + 1, 0, n);
    }
    // If already filled
    if (board[i][j] != 0) {
        return sudokusolver(board, i, j + 1, n);
    }
    // We try to fill a number
    for (int num = 1; num <= 9; num++) {
        // Check if num can be filled
        if (isvalid(board, i, j, num, n)) {
            board[i][j] = num;
            bool subans = sudokusolver(board, i, j + 1, n);
            if (subans) {
                return true;
            }
            // Backtrack if not true --> undo changes;
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n = 9;
    int board[9][9];

    cout << "Enter the Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << "\nSolving the Sudoku..." << endl;
    if (!sudokusolver(board, 0, 0, n)) {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}

