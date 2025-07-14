#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;

    int perfectSumRecursive(int idx, int target, vector<int> &arr) {
        if (target == 0) {
            return 1;
        }

        if (idx == 0) {
            return arr[0] == target;
        }

        int notPick = perfectSumRecursive(idx - 1, target, arr);

        int pick = 0;
        if (arr[idx] <= target) {
            pick = perfectSumRecursive(idx - 1, target - arr[idx], arr);
        }
        return (pick + notPick) % mod;
    }

    int perfectSumMemoization(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if (target == 0) {
            return dp[idx][target] = 1;
        }

        if (idx == 0) {
            return arr[0] == target;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int notPick = perfectSumMemoization(idx - 1, target, arr, dp);

        int pick = 0;
        if (arr[idx] <= target) {
            pick = perfectSumMemoization(idx - 1, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = (pick + notPick) % mod;
    }

    int perfectSumTabulation(int idx, int target, vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        if (arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int k = 1; k <= target; k++) {
                int notPick = dp[idx - 1][k];

                int pick = 0;
                if (arr[idx] <= k) {
                    pick = (dp[idx - 1][k - arr[idx]]) % mod;
                }
                dp[idx][k] = (pick + notPick) % mod;
            }
        }
        return dp[n - 1][target];
    }

    int perfectSumTabulationSpaceOptimized(int idx, int target, vector<int> &arr) {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        if(arr[0] <= target) {
            prev[arr[0]] = 1;
        }

        for(int idx = 1; idx < n; idx++) {
            vector<int> curr(target + 1, 0);
            curr[0] = 1;
            for(int k = 1; k <= target; k++) {
                int notPick = prev[k];

                int pick = 0;
                if(arr[idx] <= k) {
                    pick = prev[k - arr[idx]];
                }

                curr[k] = (pick + notPick) % mod;
            }
            prev = curr;
        }
        return prev[target];
    }

public:
    int perfectSum(vector<int> &arr, int K) {
        int n = arr.size();
        // return perfectSumRecursive(0, K, arr);
        // vector<vector<int>> dp(n, vector<int>(K + 1, -1));
        // return perfectSumMemoization(n - 1, K, arr, dp);
        // return perfectSumTabulation(n - 1, K, arr);
        return perfectSumTabulationSpaceOptimized(n - 1, K, arr);
    }
};

int main() {
    vector<int> arr = {2, 2, 2, 2};
    cout << Solution().perfectSum(arr, 4) << endl;
    return 0;
}