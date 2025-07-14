#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int minimumTotalRecursive(int idx, int col, vector<vector<int>>& triangle) {
        if (idx == triangle.size() - 1) {
            return triangle[idx][col];
        }
        int down = triangle[idx][col] + minimumTotalRecursive(idx + 1, col, triangle);
        int diagonal = triangle[idx][col] + minimumTotalRecursive(idx + 1, col + 1, triangle);
        return min(down, diagonal);
    }

    int minimumTotalMemoization(int idx, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (idx == triangle.size() - 1) {
            return triangle[idx][col];
        }
        if (dp[idx][col] != -1) {
            return dp[idx][col];
        }
        int down = triangle[idx][col] + minimumTotalMemoization(idx + 1, col, triangle, dp);
        int diagonal = triangle[idx][col] + minimumTotalMemoization(idx + 1, col + 1, triangle, dp);
        return dp[idx][col] = min(down, diagonal);
    }

    int minimumTotalTabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i].push_back(-1);
            }
        }
        for(int i = 0; i < n; i++) {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int down = dp[i+1][j];
                int diagonal = INT_MAX;
                if(j+1 <= i) {
                    diagonal = dp[i+1][j+1];
                }
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
        return dp[0][0];
    }
    int minimumTotalTabulationSpaceOptimized(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);

        for (int j = 0; j < n; j++) {
            prev[j] = triangle[n - 1][j];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(i + 1);
            for (int j = 0; j <= i; j++) {
                int down = prev[j];
                int diagonal = prev[j + 1];
                curr[j] = triangle[i][j] + min(down, diagonal);
            }
            prev = curr;
        }

        return prev[0];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i].push_back(-1);
            }
        }
        // return minimumTotalRecursive(0, 0, triangle);
        // return minimumTotalMemoization(0, 0, triangle, dp);
        // return minimumTotalTabulation(triangle);
        return minimumTotalTabulationSpaceOptimized(triangle);
    }
};


int main() {
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    // vector<vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}