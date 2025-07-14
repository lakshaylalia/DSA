#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int knapsack01Recursive(int idx, int W, vector<int> &val, vector<int> &wt) {
        if(W == 0) {
            return 0;
        }
        if(idx == 0) {
            if(wt[0] <= W) {
                return val[0];
            } else {
                return 0;
            }
        }

        int skip = knapsack01Recursive(idx - 1, W, val, wt);
        int take = 0;
        if(wt[idx] <= W) {
            take = val[idx] + knapsack01Recursive(idx - 1, W-wt[idx], val, wt);
        }

        return max(skip, take);
    }

    int kanpsack01Memoization(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        if(W == 0) {
            return 0;
        }

        if(idx == 0) {
            if(wt[0] <= W) {
                return val[0];
            } else {
                return 0;
            }
        }

        if(dp[idx][W] != -1) {
            return dp[idx][W];
        }

        int skip = kanpsack01Memoization(idx - 1, W, val, wt, dp);
        int take = 0;
        if(wt[idx] <= W) {
            take = val[idx] + kanpsack01Memoization(idx - 1, W-wt[idx], val, wt, dp);
        }
        return dp[idx][W] = max(skip, take);
    }

    int kanpsack01Tabulation(int n, int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for(int i = wt[0]; i <= W; i++) {
            dp[0][i] = val[0];
        }
        for(int  idx = 1; idx < n; idx++) {
            for(int w = 0; w <= W; w++) {
                int skip = dp[idx - 1][w];
                int take = 0;
                if(wt[idx] <= w) {
                    take = val[idx] + dp[idx - 1][w - wt[idx]];
                }
                dp[idx][w] = max(skip, take);
            }
        }
        return dp[n - 1][W];
    }

    // int kanpsack01SpaceOptimized(int n, int W, vector<int> &val, vector<int> &wt) {
    //     vector<int> prev(W + 1, 0);
    //     for(int i = wt[0]; i <= W; i++) {
    //         prev[i] = val[0];
    //     }

    //     for(int idx = 1; idx < n; idx++) {
    //         vector<int> curr(W + 1, 0);
    //         for(int w = 0; w <= W; w++) {
    //             int skip = prev[w];
    //             int take = 0;
    //             if(wt[idx] <= w) {
    //                 take = val[idx] + prev[w- wt[idx]];
    //             }
    //             curr[w] = max(skip, take);
    //         }
    //         prev = curr;
    //     }
    //     return prev[W];
    // }

    int kanpsack01SpaceOptimized(int n, int W, vector<int> &val, vector<int> &wt) {
        vector<int> prev(W + 1, 0);
        for(int i = wt[0]; i <= W; i++) {
            prev[i] = val[0];
        }

        for(int idx = 1; idx < n; idx++) {
            for(int w = W; w >= 0; w--) {
                int skip = prev[w];
                int take = 0;
                if(wt[idx] <= w) {
                    take = val[idx] + prev[w- wt[idx]];
                }
                prev[w] = max(skip, take);
            }
        }
        return prev[W];
    }

public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        // return knapsack01Recursive(n - 1, W, val, wt);
        // // vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        // // return kanpsack01Memoization(n - 1, W, val, wt, dp);
        // return kanpsack01Tabulation(n, W, val, wt);
        return kanpsack01SpaceOptimized(n, W, val, wt);
    }
};

int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    cout << Solution().knapsack01(wt, val, wt.size(), 50) << endl; // 220

    // vector<int> val = {10, 40, 30, 50};
    // vector<int> wt = {5, 4, 6, 3};
    // cout << Solution().knapsack01(wt, val, wt.size(), 10) << endl;  // 90

    // vector<int> val = {20, 5, 10, 40, 15, 25};
    // vector<int> wt = {1, 2, 3, 8, 7, 4};
    // cout << Solution().knapsack01(wt, val, wt.size(), 10) << endl;  // 60
    return 0;
}