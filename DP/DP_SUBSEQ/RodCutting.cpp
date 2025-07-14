#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int Recursive(int idx, int len, vector<int> &price) {
        if(len == 0) {
            return 0;
        }
        if(idx == 0) {
            return len * price[0];
        }
        int skip = Recursive(idx - 1, len, price);
        int take = 0;
        if(idx+1 <= len) {
            take = price[idx] + Recursive(idx, len - (idx+1), price);
        }
        return max(skip, take);
    }

    int Memoization(int idx, int len, vector<int> &price, vector<vector<int>> &dp) {
        if(len == 0) {
            return 0;
        }
        if(idx == 0) {
            return len * price[0];
        }
        if(dp[idx][len] != -1) {
            return dp[idx][len];
        }

        int skip = Memoization(idx - 1, len, price, dp);
        int take = 0;
        if(idx+1 <= len) {
            take = price[idx] + Memoization(idx, len - (idx+1), price, dp);
        }
        return dp[idx][len] = max(skip, take);
    }

    int Tabulation(int n, vector<int> &price) {
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        for(int i = 1; i <= n; i++) {
            dp[0][i] = i * price[0];
        }
        for(int idx = 1; idx < n; idx++) {
            for(int len = 1; len <= n; len++) {
                int skip = dp[idx-1][len];
                int take = 0;
                if(idx+1 <= len) {
                    take = price[idx] + dp[idx][len - (idx+1)];
                }
                dp[idx][len] = max(skip, take);
            }
        }
        return dp[n-1][n];
    }

    // int SpaceOptimized(int n, vector<int> &price) {
    //     vector<int> prev(n+1, 0);
    //     for(int i = 1; i <= n; i++) {
    //         prev[i] = i * price[0];
    //     }

    //     for(int idx = 1; idx < n; idx++) {
    //         for(int len = n; len >= 1; len--) {
    //             int skip = prev[len];
    //             int take = 0;
    //             if(idx+1 <= len) {
    //                 take = price[idx] + prev[len - (idx+1)];
    //             }
    //             prev[len] = max(skip, take);
    //         }
    //     } 
    //     return prev[n];
    // }

    int SpaceOptimized(int n, vector<int> &price) {
        vector<int> prev(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prev[i] = i * price[0];
        }

        for(int idx = 1; idx < n; idx++) {
            for(int len = 1; len <= n; len++) {
                int skip = prev[len];
                int take = 0;
                if(idx+1 <= len) {
                    take = price[idx] + prev[len - (idx+1)];
                }
                prev[len] = max(skip, take);
            }
        } 
        return prev[n];
    }

    public:
    int rodCutting(vector<int> price, int n) {
        // return Recursive(n-1, n, price);
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return Memoization(n-1, n, price, dp);
        // return Tabulation(n, price);
        return SpaceOptimized(n, price);

    }
};

int main() {
    vector<int> price = {1, 5, 8, 9};
    cout << Solution().rodCutting(price, 4);
    return 0;
}