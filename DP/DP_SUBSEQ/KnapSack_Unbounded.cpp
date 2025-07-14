#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
   int Recursive(int idx, int W, vector<int>& wt, vector<int>& val){
        if(W == 0) {
            return 0;
        }
        if(idx == 0) {
            return val[0] * (W/wt[0]);
        }

        int skip = Recursive(idx-1, W, wt, val);
        int take = INT_MIN;
        if(wt[idx] <= W) {
            take = val[idx] + Recursive(idx, W-wt[idx], wt, val);
        }
        return max(skip, take);
    }

    int Memoization(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        if(W == 0) {
            return 0;
        }
        if(idx == 0) {
            return val[0] * (W/wt[0]);
        }
        if(dp[idx][W] != -1) {
            return dp[idx][W];
        }

        int skip = Memoization(idx-1, W, wt, val, dp);
        int take = INT_MIN;
        if(wt[idx] <= W) {
            take = val[idx] + Memoization(idx, W-wt[idx], wt, val, dp);
        }
        return dp[idx][W] = max(skip, take);
    }

    int Tabulation(int n, int W, vector<int>& wt, vector<int>& val) {
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int i = 0; i <= W; i++) {
            dp[0][i] = val[0] * (i/wt[0]);
        }

        for(int idx = 1; idx < n; idx++) {
            for(int w = 0; w <= W; w++) {
                int skip = dp[idx-1][w];
                int take = INT_MIN;
                if(wt[idx] <= w) {
                    take = val[idx] + dp[idx][w-wt[idx]];
                }
                dp[idx][w] = max(skip, take);
            }
        }
        return dp[n-1][W];
    }

    // int SpaceOptimized(int n, int W, vector<int>& wt, vector<int>& val) {
    //     vector<int> prev(W+1, 0);
    //     for(int w = 0; w <= W; w++) {
    //         prev[w] = val[0] * (w/wt[0]);
    //     }
    //     for(int idx = 1; idx < n; idx++) {
    //         vector<int> curr(W+1, 0);
    //         for(int w = 0; w <= W; w++) {
    //             int skip = prev[w];
    //             int take = INT_MIN;
    //             if(wt[idx] <= w) {
    //                 take = val[idx] + curr[w-wt[idx]];
    //             }
    //             curr[w] = max(skip, take);
    //         }
    //         prev = curr;
    //     }
    //     return prev[W];
    // }

    int SpaceOptimized(int n, int W, vector<int>& wt, vector<int>& val) {
        vector<int> prev(W+1, 0);
        for(int w = 0; w <= W; w++) {
            prev[w] = val[0] * (w/wt[0]);
        }
        for(int idx = 1; idx < n; idx++) {
            for(int w = W; w >= 0; w--) {
                int skip = prev[w];
                int take = INT_MIN;
                if(wt[idx] <= w) {
                    take = val[idx] + prev[w-wt[idx]];
                }
                prev[w] = max(skip, take);
            }
        }
        return prev[W];
    }

   public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        // return Recursive(n-1, W, wt, val);
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return Memoization(n-1, W, wt, val, dp);
        // return Tabulation(n, W, wt, val);
        return SpaceOptimized(n, W, wt, val);
    }
};


int main() {
    vector<int> val = {29,30};
    vector<int> wt = {18,78};
    cout << Solution().unboundedKnapsack(wt, val, 2, 242);
    return 0;
}