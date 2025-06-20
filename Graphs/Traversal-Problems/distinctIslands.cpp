#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
  vector<int> delRow = {-1, 0, 1, 0};
  vector<int> delCol = {0, 1, 0, -1};

  bool isValid(int row, int col, int n, int m){
    if(row < 0 || col < 0 || row >= n || col >= m) return false;
    return true;
  }
  
  void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis, vector<pair<int, int>> &shape, int baseRow, int baseCol){
    int n = grid.size(), m = grid[0].size();
    vis[row][col] = 1;
    shape.push_back({row - baseRow, col - baseCol});
    for(int i = 0; i < 4; i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if(isValid(nRow, nCol, n, m) && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
            dfs(nRow, nCol, grid, vis, shape, baseRow, baseCol);
        }
    }
  }
  

public:
    int countDistinctIslands(vector<vector<int>> &grid){
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> unique;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, vis, shape, i, j);
                    unique.insert(shape);
                }
            }
        }
        return unique.size();
    }
};

int main() {
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,1,1}};
    cout << Solution().countDistinctIslands(grid) << endl;
    return 0;
}