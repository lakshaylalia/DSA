#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }
        return true;
    }

    int maxPathSumRecursive(int row, int col, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(!isValid(row, col, n, m)) {
            return INT_MAX;
        }
        if(row == n-1 && col == m-1) {
            return grid[row][col];
        }
        int right = maxPathSumRecursive(row, col+1, grid);
        int down = maxPathSumRecursive(row+1, col, grid);
        return min(right, down) + grid[row][col];
    }

    int maxPathSumMemoization(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size(), m = grid[0].size();
        if(!isValid(row, col, n, m)) {
            return INT_MAX;
        }
        if(row == n-1 && col == m-1) {
            dp[row][col] = grid[row][col];
            return dp[row][col];
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int right = maxPathSumMemoization(row, col+1, grid, dp);
        int down = maxPathSumMemoization(row+1, col, grid, dp);
        return min(right, down) + grid[row][col];
    }

    int maxPathSumTabulation(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(isValid(i, j+1, n, m)) {
                    right = dp[i][j+1];
                }
                if(isValid(i+1, j, n, m)) {
                    down = dp[i+1][j];
                }
                dp[i][j] = min(right, down) + grid[i][j];
            }
        }
        return dp[0][0];
    }

    int maxPathSumTabulationSpaceOptimized(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> prev(m, 0);
        for(int i = n-1; i >= 0; i--) {
            vector<int> temp(m, 0);
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) {
                    temp[j] = grid[i][j];
                    continue;
                }
                int right = INT_MAX, down = INT_MAX;
                if(j+1 < m) {
                    right = temp[j+1];
                }
                if(i+1 < n) {
                    down = prev[j];
                }
                temp[j] = min(right, down) + grid[i][j];
            }
            prev = temp;
        }
        return prev[0];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        // int n = grid.size(), m = grid[0].size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return maxPathSumRecursive(0, 0, grid);
        // return maxPathSumMemoization(0, 0, grid, dp);
        // return maxPathSumTabulation(grid);
        return maxPathSumTabulationSpaceOptimized(grid);
    }
};

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}