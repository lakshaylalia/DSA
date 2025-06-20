#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
      bool isValid(int &i, int &j, int &n, int &m) {
        
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        
        return true;
    }
   void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, vector<vector<int>> &visited, int delRows[], int delCols[]) {
        int n = grid.size();
        int m = grid[0].size(); 

        while(!q.empty()){
            auto cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            for(int i = 0; i  < 4; i++){
                int nRow = row + delRows[i];
                int nCol = col + delCols[i];
                if(isValid(nRow, nCol, n, m) && !visited[nRow][nCol] && grid[nRow][nCol] == 1) {
                    visited[nRow][nCol] = true;
                    q.push({ nRow, nCol });
                }
            }
        }
   }


    
    void dfs(int row, int col, vector<vector<int>>& grid, int delRows[], int delCols[]) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) return;
        grid[row][col] = 0;
        for(int i = 0; i < 4; i++) {
            int nRow = row + delRows[i];
            int nCol = col + delCols[i];
            dfs(nRow, nCol, grid, delRows, delCols);
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int enclaves = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> temp = grid;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};




        // queue <pair<int,int>> q;
        // vector<vector<bool>> vis(n, vector<bool>(m, false));
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++) {
        //         if((i == 0 || i == n-1 || j == 0 || j == m-1) &&grid[i][j] == 1) {
        //          vis[i][j] = true;
        //          q.push({i, j});
        //         }
        //     }
        // }
        // bfs(grid, q, vis);
        // for(int i=0; i < n; i++) {
        //     for(int j=0; j < m; j++){
        //         if(grid[i][j] == 1 && !vis[i][j])
        //             enclaves++;
        //     }
        // }

      
        for(int i = 0; i < n; i++) {
            if(temp[i][0] == 1)
                dfs(i, 0, temp, delRow, delCol);
            if(temp[i][m - 1] == 1)
                dfs(i, m - 1, temp, delRow, delCol);
        }

        for(int j = 0; j < m; j++) {
            if(temp[0][j] == 1)
                dfs(0, j, temp, delRow, delCol);
            if(temp[n - 1][j] == 1)
                dfs(n - 1, j, temp, delRow, delCol);
        }

      
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(temp[i][j] == 1) enclaves++;
            }
        }

        return enclaves;
    }
};


int main() {
    vector<vector<int>> grid = {{0,0,0,1},{0,0,0,1},{0, 1, 1, 0},{0, 0, 1, 0},{0, 0, 0, 0}};
    cout << Solution().numEnclaves(grid) << endl;
    return 0;
}