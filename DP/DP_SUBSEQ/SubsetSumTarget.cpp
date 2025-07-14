#include <bits/stdc++.h>
using namespace std;

class Solution{  
private:
   bool Recursive(int idx, int target, vector<int> &arr) {
        if(target == 0) {
            return true;
        }

        if(idx >= arr.size() || target < 0) {
            return false;
        }

        if(Recursive(idx+1, target-arr[idx], arr)) {
            return true;
        } 

        if(Recursive(idx+1, target, arr)) {
            return true;
        }
        return false;
    } 

   bool isSubsetSumRecursive(int idx, int target, vector<int> &arr) {
        if(target == 0) {
            return true;
        }
        if(idx == 0) {
            return (arr[0] == target);
        }

        bool notTake = isSubsetSumRecursive(idx-1, target, arr);

        bool take = false;
        if(target >= arr[idx]) {
            take = isSubsetSumRecursive(idx-1, target-arr[idx], arr);
        }

        return take || notTake;
    }

   bool isSubsetSumMemoization(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if(target == 0) {
            return true;
        }
        if(idx == 0) {
            return (arr[0] == target);
        }
        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int notTake = isSubsetSumMemoization(idx-1, target, arr, dp);
        int take = false;
        if(target >= arr[idx]) {
            take = isSubsetSumMemoization(idx-1, target-arr[idx], arr, dp);
        }
        return dp[idx][target] = take || notTake;
    }

    bool isSubsetSumTabulation(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(k+1, false));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        for(int idx = 1; idx < n; idx++) {
            for(int target = 1; target <= k; target++) {
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(target >= arr[idx]) {
                    take = dp[idx-1][target-arr[idx]];
                }
                dp[idx][target] = take || notTake;
            }
        }
        return dp[n-1][k];
    }

    bool isSubsetSumTabulationSpaceOptimized(vector<int> &arr, int k) {
        int n = arr.size();
        vector<bool> prev(k+1, false);
        prev[0] = true;
        for(int idx = 0; idx < n; idx++) {
            vector<bool> curr(k+1, false);
            curr[0] = true;
            for(int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if(target >= arr[idx]) {
                    take = prev[target-arr[idx]];
                }
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[k];
    }

public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        // return isSubsetSumRecursive(n-1, target, arr);
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return isSubsetSumMemoization(n-1, target, arr, dp);
        // return isSubsetSumTabulation(arr, target);
        return isSubsetSumTabulationSpaceOptimized(arr, target);

    }
};

int main() {
    vector<int> arr = {7, 54, 4, 12, 15, 5};
    cout << Solution().isSubsetSum(arr, 9) << endl;
    return 0;
}