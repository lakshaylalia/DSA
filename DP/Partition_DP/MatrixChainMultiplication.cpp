#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
  int Recurssive(int i, int j, vector<int> &arr) {
    if(i == j) {
      return 0;
    }
    int mini = 1e9;
    for(int k = i; k < j; k++) {
    int steps = arr[i-1]*arr[k]*arr[j] + Recurssive(i, k, arr) + Recurssive(k+1, j, arr);
      mini = min(mini, steps);
    }
    return mini;
  }

  int Memoization(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if(i == j) {
      return 0;
    }

    if(dp[i][j] != -1) {
      return dp[i][j];
    }
    int mini = 1e9;
    for(int k = i; k < j; k++) {
      int steps = arr[i-1]*arr[k]*arr[j] + Memoization(i, k, arr, dp) + Memoization(k+1, j, arr, dp);
      mini = min(mini, steps);
    }
    return dp[i][j] = mini;
  }

    
public:
  int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n-1; i >= 1; i--) {
      for(int j = i+1; j < n; j++) {
        int mini = 1e9;
        for(int k = i; k < j; k++) {
          int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
          mini = min(mini, steps);
        }
        dp[i][j] = mini;
      }
    }
     return dp[1][n-1];
  }
};

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << Solution().matrixMultiplication(arr);
    return 0;
}