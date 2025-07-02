#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& obstacleGrid) {
        if(row < 0 || col < 0 || row >= n || col >= m || obstacleGrid[row][col] == 1) {
            return false;
        }
        return true;
    }

    long long validPathRecurssion(int row, int col, vector<vector<int>>& obstacleGrid) {
        if(!isValid(row, col, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid)) {
            return 0;
        }
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(row == n-1 && col == m-1) {
            return 1;
        }
        long long right = validPathRecurssion(row, col+1, obstacleGrid);
        long long down = validPathRecurssion(row+1, col, obstacleGrid);
        return right + down;
    }

    long long validPathMemoization(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<long long>>& dp) {
        if(!isValid(row, col, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid)) {
            return 0;
        }

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        if(row == n-1 && col == m-1) {
            dp[row][col] = 1;
            return 1;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        long long right = validPathMemoization(row, col+1, obstacleGrid, dp);
        long long down = validPathMemoization(row+1, col, obstacleGrid, dp);
        return dp[row][col] = right + down;
    }

    long long validPathTabulation(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        dp[n-1][m-1] = (obstacleGrid[n-1][m-1] == 1) ? 0 : 1;

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(i == n-1 && j == m-1) continue;

                if(!isValid(i, j, n, m, obstacleGrid)) {
                    dp[i][j] = 0;
                    continue;
                }

                long long right = 0, down = 0;
                if(isValid(i, j+1, n, m, obstacleGrid)) {
                    right = dp[i][j+1];
                }
                if(isValid(i+1, j, n, m, obstacleGrid)) {
                    down = dp[i+1][j];
                }
                dp[i][j] = right + down;
            }
        }
        return dp[0][0];
    }

    long long validPathSpaceOptimization(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<long long> prev(m, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<long long> temp(m, 0);
            for (int j = m - 1; j >= 0; j--) {
                if (!isValid(i, j, n, m, obstacleGrid)) {
                    temp[j] = 0;
                    continue;
                }

                if (i == n - 1 && j == m - 1) {
                    temp[j] = 1;
                    continue;
                }

                long long down = 0, right = 0;
                if (isValid(i + 1, j, n, m, obstacleGrid)) {
                    down = prev[j];
                }
                if (isValid(i, j + 1, n, m, obstacleGrid)) {
                    right = temp[j + 1];
                }

                temp[j] = down + right;
            }
            prev = temp;
        }

        return prev[0];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        // return validPathRecurssion(0, 0, obstacleGrid);
        // return validPathMemoization(0, 0, obstacleGrid, dp);
        // return validPathTabulation(obstacleGrid);
        return validPathSpaceOptimization(obstacleGrid);
    }
};


int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}}; 
    // vector<vector<int>> obstacleGrid = {{0,1}, {0,1}}; 
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}