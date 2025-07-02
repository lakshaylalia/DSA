#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxPointsRecurssion(int idx, int sum, int prev, vector<vector<int>> &matrix) {
        if(idx >= matrix.size()) {
            return sum;
        }
        int maxPoints = 0;
        for(int i = 0; i < 3; i++) {
            if(i != prev) {
                maxPoints = max(maxPoints, maxPointsRecurssion(idx + 1, sum + matrix[idx][i], i, matrix));
            }
        }
        return maxPoints;
    }

    int maxPointsRecurssionMemoization(int idx, int prev, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(idx >= matrix.size()) {
            return 0;
        }
        int maxPoints = 0;
        for(int i = 0; i < 3; i++) {
            if(i != prev) {
                if(dp[idx][i] != -1) {
                    maxPoints = max(maxPoints, dp[idx][i]);
                } else {
                    dp[idx][i] = matrix[idx][i] + maxPointsRecurssionMemoization(idx + 1, i, matrix, dp);
                    maxPoints = max(maxPoints, dp[idx][i]);
                }
            }
        }
        return maxPoints;
    }

    int maxPointsRecurssionTabulation(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for(int j = 0; j < 3; j++) {
        dp[n-1][j] = matrix[n-1][j];
    }

    for(int i = n-2; i >= 0; i--) {
        for(int j = 0; j < 3; j++) {
            int best = 0;
            for(int k = 0; k < 3; k++) {
                if(k != j) {
                    best = max(best, dp[i+1][k]);
                }
            }
            dp[i][j] = matrix[i][j] + best;
        }
    }

    int maxPoints = max({dp[0][0], dp[0][1], dp[0][2]});
    return maxPoints;
}

int maxPointsRecurssionTabulationSpaceOptimized(vector<vector<int>> &matrix) { 
    int n = matrix.size();
    vector<int> prev(3);
    for(int i = 0; i < 3; i++) {
        prev[i] = matrix[n-1][i];
    }

    for(int i = n-2; i >= 0; i--) {
        vector<int> curr(3, 0);
        
        for(int j = 0; j < 3; j++) {
            int best = 0;
            for(int k = 0; k < 3; k++) {
                if(k != j) {
                    best = max(best, prev[k]);
                }
            }
            curr[j] = matrix[i][j] + best;
        }

        prev = curr;
    }

    return max({prev[0], prev[1], prev[2]});
}

public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        // return maxPointsRecurssion(0, 0, -1, matrix);
        // return maxPointsRecurssionMemoization(0, -1, matrix, dp);
        // return maxPointsRecurssionTabulation(matrix);
        return maxPointsRecurssionTabulationSpaceOptimized(matrix);
    }
};

int main() {
    vector<vector<int>> matrix = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    // vector<vector<int>> matrix = {{70, 40, 10}, {180, 20, 5}, {200, 60, 30}};
    // vector<vector<int>> matrix = {{20, 10, 10}, {20, 10, 10}, {20, 30, 10}};
    cout << Solution().ninjaTraining(matrix) << endl;
    return 0;
}