#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int n) {
        if(row < 0 || col < 0 || row >= n || col >= n) {
            return false;
        }
        return true;
    }

    int maxFallingPathSumRecursive(int row, int col, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!isValid(row, col, n)) {
            return INT_MIN;
        }
        if(row == n-1) {
            return matrix[row][col];
        }
        int down = maxFallingPathSumRecursive(row + 1, col, matrix);
        int left = maxFallingPathSumRecursive(row + 1, col - 1, matrix);
        int right = maxFallingPathSumRecursive(row + 1, col + 1, matrix);
        return matrix[row][col] + max({down, left, right});
    }

    int maxFallingPathSumMemoization(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        if(!isValid(row, col, n)) {
            return INT_MIN;
        }
        if(row == n-1) {
            return dp[row][col] = matrix[row][col];
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int down = maxFallingPathSumMemoization(row + 1, col, matrix, dp);
        int left = maxFallingPathSumMemoization(row + 1, col - 1, matrix, dp);
        int right = maxFallingPathSumMemoization(row + 1, col + 1, matrix, dp);
        return dp[row][col] = matrix[row][col] + max({down, left, right});
    }

    int maxFallingPathSumTabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }
        for(int row = n-2; row >= 0; row--) {
            for(int col = 0; col < n; col++) {
                int down = dp[row + 1][col];
                int left = col > 0 ? dp[row + 1][col-1] : INT_MIN;
                int right = col < n-1 ? dp[row + 1][col+1] : INT_MIN;
                dp[row][col] = matrix[row][col] + max({down, left, right});
            }
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }

    int maxFallingPathSumTabulationSpaceOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        for(int i = 0; i < n; i++) {
            prev[i] = matrix[n-1][i];
        }
        for(int row = n-2; row >= 0; row--) {
            vector<int> curr(n);
            for(int col = 0; col < n; col++) {
                int down = prev[col];
                int left = col > 0 ? prev[col-1] : INT_MIN;
                int right = col < n-1 ? prev[col+1] : INT_MIN;
                curr[col] = matrix[row][col] + max({down, left, right});
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }

public:
    int maxFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MIN;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = 0; i < n; i++) {
        //     ans = max(ans, maxFallingPathSumRecursive(0, i, matrix));
        //     ans = max(ans, maxFallingPathSumMemoization(0, i, matrix, dp));
        // }
        // return ans;
        // return maxFallingPathSumTabulation(matrix);
        return maxFallingPathSumTabulationSpaceOptimized(matrix);
    }
};


int main() {
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << Solution().maxFallingPathSum(matrix) << endl;
    return 0;
}