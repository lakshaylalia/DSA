#include <bits/stdc++.h>
using namespace std;

bool canPlaceQueen(int row, int col, vector<vector<int>>& board) {
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 1) return false;
    }

    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 1) return false;
        i--; j--;
    }

    i = row - 1, j = col + 1;
    while (i >= 0 && j < board.size()) {
        if (board[i][j] == 1) return false;
        i--; j++;
    }

    return true;
}

void Queens(int row, vector<vector<string>>& ans, vector<vector<int>>& board) {
    if (row == board.size()) {
        vector<string> combo;
        for (int i = 0; i < board.size(); i++) {
            string str = "";
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 1) str += 'Q';
                else str += '.';
            }
            combo.push_back(str);
        }
        ans.push_back(combo);
        return;
    }

    for (int i = 0; i < board.size(); i++) {
        if (canPlaceQueen(row, i, board)) {
            board[row][i] = 1;
            Queens(row + 1, ans, board);
            board[row][i] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    Queens(0, ans, board);
    return ans;
}

int main() {
    int n = 5;
    vector<vector<string>> result = solveNQueens(n);
    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}



