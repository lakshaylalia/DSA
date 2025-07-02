#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int m, int n) {
        if(row < 0 || col < 0 || row >= m || col >= n) {
            return false;
        }
        return true;
    }

    int totalPathsRecurssion(int row, int col, int m, int n) {
        if(row == m-1 && col == n-1) {
            return 1;
        }

        if(!isValid(row, col, m, n)) {
            return 0;
        }

        int down = totalPathsRecurssion(row+1, col, m, n);
        int right = totalPathsRecurssion(row, col+1, m, n);

        return down + right;
    }

    int totalPathsMemoization(int row, int col, int m, int n, vector<vector<int>> &dp) {
        if(row == m-1 && col == n-1) {
            dp[row][col] = 1;
            return dp[row][col];
        }
        if(!isValid(row, col, m, n)) {
            return 0;
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        dp[row][col] = totalPathsMemoization(row+1, col, m, n, dp) + totalPathsMemoization(row, col+1, m, n, dp);
        return dp[row][col];
    }

    int totalPathsTabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) {
                    dp[i][j] = 1;
                    continue;
                }
                int down = 0, right = 0;
                if(i+1 < m) {
                    down = dp[i+1][j];
                }
                if(j+1 < n) {
                    right = dp[i][j+1];
                }
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }

    int toatlPathsSpaceOptimization(int m, int n) {
        vector<int> prev(n, 0);

        for(int i = m-1; i >= 0; i--) {
            vector<int> temp(n, 0);
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) {
                    temp[j] = 1;
                    continue;
                } 
                int down = 0, right = 0;
                if(i+1 < m) {
                    down = prev[j];
                }
                if(j+1 < n) {
                    right = temp[j+1];
                }
                temp[j] = down + right;

            }
            prev = temp;
        }
        return prev[0];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return totalPathsRecurssion(0, 0, m, n);
        // return totalPathsMemoization(0, 0, m, n, dp);
        // return totalPathsTabulation(m, n);
        return toatlPathsSpaceOptimization(m, n);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        cout << Solution().uniquePaths(m, n) << endl;
    }
    return 0;
}