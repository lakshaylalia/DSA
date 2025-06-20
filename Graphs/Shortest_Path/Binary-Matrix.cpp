#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& grid) {
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 1) return false;
        return true;
    }

    void dfs(int row, int col, int &shortest, int current, vector<vector<int>> grid){
        if(current >= shortest) return;
        int n = grid.size(), m = grid[0].size(); 
        if(row == n - 1 && col == m - 1) {
            shortest = min(shortest, current);
            return;
        }
        grid[row][col] = 1;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int nRow = row + i;
                int nCol = col + j;
                if(isValid(nRow, nCol, n, m, grid)) {
                    dfs(nRow, nCol, shortest, current + 1, grid);
                }
            }
        }
        grid[row][col] = 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int shortest = INT_MAX;
        dfs(0, 0, shortest, 0, grid);
        return (shortest != INT_MAX) ? shortest + 1 : -1;
    }
};

int main() {
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << Solution().shortestPathBinaryMatrix(grid) << endl;
    return 0;
}