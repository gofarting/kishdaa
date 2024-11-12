#include <iostream>
using namespace std;

bool isSafe(int queens[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i] == col) {
            return false;
        }
        if (queens[i] - col == i - row || queens[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int queens[], int row, int n) {
    if (row == n) {
        cout << "[";
        for (int i = 0; i < n; i++) {
            cout << (queens[i] + 1);
            if (i < n - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            if (solveNQueens(queens, row + 1, n)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    int queens[n];
    solveNQueens(queens, 0, n);

    return 0;
}