#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
   bool isValid(int row, int col, int n, int m){
    if(row < 0 || col < 0 || row >= n || col >= m) return false;
    return true;
   }

   vector<int> delRow = {-1, 0, 1, 0};
   vector<int> delCol = {0, 1, 0, -1};

   void dfs(vector<vector<char>> &board, int row, int col){
    int n = board.size(), m = board[0].size();
    for(int i = 0; i < 4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(isValid(nRow, nCol, n, m) && board[nRow][nCol] == 'O'){
            board[nRow][nCol] = 'Z';
            dfs(board, nRow, nCol);
        }
    }
   }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'Z';
                dfs(board, 0, i);
            };
            if(board[n - 1][i] == 'O'){
                board[n - 1][i] = 'Z';
                dfs(board, n - 1, i);
            };
        }

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'Z';
                dfs(board, i, 0);
            };
            if(board[i][m - 1] == 'O'){
                board[i][m - 1] = 'Z';
                dfs(board, i, m - 1);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Z') board[i][j] = 'O';
            }
        }
    }
};

int main() {
    vector<vector<char>> board = {{'O', 'X', 'X', 'O', 'X'}, {'X', 'O', 'O', 'X', 'O'}, {'X', 'O', 'X', 'O', 'X'}, {'O', 'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X', 'O'}};
    Solution().solve(board);
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}