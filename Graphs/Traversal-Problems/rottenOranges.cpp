#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   int time = 0;
   vector<int> delRow = {-1, 0, 1, 0};
   vector<int> delCol = {0, 1, 0, -1};

   bool isValid(int row, int col, int n, int m){
    if(row < 0 || row >= n ) return false;
    if(col < 0 || col >= m) return false;

    return true;
   }


   void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col){
    if(visited[row][col] || grid[row][col] == 0) return;
    grid[row][col] = 2;
    visited[row][col] = true;
    for(int i = 0; i < 4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        dfs(grid, visited, nRow, nCol);
    }
    time++;
   }

   void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q){
    int n = grid.size(), m = grid[0].size();
    while(!q.empty()){
        int size = q.size();
        time++;
        for(int i = 0; i < size; i++){
            auto cell = q.front();
            int row = cell.first, col = cell.second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRwow = row+ delRow[i];
                int nCol = col + delCol[i];
                if(isValid(nRwow, nCol, n, m) && !visited[nRwow][nCol] && grid[nRwow][nCol] == 1){
                    q.push({nRwow, nCol});
                    visited[nRwow][nCol] = true;
                    grid[nRwow][nCol] = 2;
                }
            }
        }
    }
   }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> visited (n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        vector<vector<int>> temp = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        bfs(temp, visited, q);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(temp[i][j] == 1) return -1;
            }
        }
        return time - 1;
    }
};

int main() {
    vector<vector<int>> grid = {{0,1,2},{0,1,2},{2,1,1}};
    cout << Solution().orangesRotting(grid) << endl;
    return 0;
}