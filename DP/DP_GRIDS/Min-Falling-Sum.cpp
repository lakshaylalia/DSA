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

    int minFallingPathSumRecursive(int row, int col, vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(!isValid(row, col, n)) {
            return INT_MAX;
        }
        if(row == n-1) {
            return matrix[row][col];
        }
        int down =  minFallingPathSumRecursive(row + 1, col, matrix);
        int left = minFallingPathSumRecursive(row + 1, col - 1, matrix);
        int right = minFallingPathSumRecursive(row + 1, col + 1, matrix);
        return matrix[row][col] + min(down, min(left, right));
    }

    int minFallingPathSumMemoization(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        if(!isValid(row, col, n)) {
            return INT_MAX;
        }
        if(row == n-1) {
            return dp[row][col] = matrix[row][col];
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int down =  minFallingPathSumMemoization(row + 1, col, matrix, dp);
        int left = minFallingPathSumMemoization(row + 1, col - 1, matrix, dp);
        int right = minFallingPathSumMemoization(row + 1, col + 1, matrix, dp);

        return dp[row][col] = matrix[row][col] + min(down, min(left, right));
    }

    int minFallingPathSumTabulation(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int row = n-2; row >= 0; row--) {
            for(int col = 0; col < n; col++) {
                int down = dp[row + 1][col];
                int left = col > 0 ? dp[row + 1][col-1] : INT_MAX;
                int right = col < n-1 ? dp[row + 1][col+1] : INT_MAX;
                dp[row][col] = matrix[row][col] + min(down, min(left, right));
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }

    int minFallingPathSumTabulationSpaceOptimized(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        for(int i = 0; i < n; i++) {
            prev[i] = matrix[n-1][i];
        }

        for(int row = n-2; row >= 0; row--) {
            vector<int> curr(n);
            for(int col = 0; col < n; col++) {
                int down = prev[col];
                int left = col > 0 ? prev[col-1] : INT_MAX;
                int right = col < n-1 ? prev[col+1] : INT_MAX;
                curr[col] = matrix[row][col] + min(down, min(left, right));
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int ans = INT_MAX;
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // for(int i = 0; i < n; i++) {
            // ans = min(ans, minFallingPathSumRecursive(0, i, matrix));
        //     ans = min(ans, minFallingPathSumMemoization(0, i, matrix, dp));
        // }
        // return ans;
        // return minFallingPathSumTabulation(matrix);
        return minFallingPathSumTabulationSpaceOptimized(matrix);
    }
};

int main() {
    // vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> matrix = {{4,3,4},{4,5,1},{4,6,2}, {4,1,4}};
    cout << Solution().minFallingPathSum(matrix) << endl;
    return 0;
}