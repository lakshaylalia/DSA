#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int changeRecursive(int idx, int target, vector<int>& coins) {
        if(target == 0) {
            return 1;
        }
        if(idx == 0) {
            return (target % coins[idx] == 0);
        }        
        int skip = changeRecursive(idx - 1, target, coins);
        int take = 0;
        if(coins[idx] <= target) {
            take = changeRecursive(idx, target - coins[idx], coins);
        }
        return skip + take;
    }

    int changeRecursiveMemo(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if(target == 0) {
            return 1;
        }
        if(idx == 0) {
            return (target % coins[idx] == 0);
        }
        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int skip = changeRecursiveMemo(idx - 1, target, coins, dp);
        int take = 0;
        if(coins[idx] <= target) {
            take = changeRecursiveMemo(idx, target - coins[idx], coins, dp);
        }
        return dp[idx][target] = skip + take;
    }

    int changeTabulation(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = 1;
            }
        }
        for(int idx = 1; idx < n; idx++) {
            for(int amt = 1; amt <= amount; amt++) {
                int skip = dp[idx-1][amt];
                int take = 0;
                if(coins[idx] <= amt) {
                    take = dp[idx][amt - coins[idx]];
                }
                dp[idx][amt] = skip + take;
            }
        }
        return dp[n - 1][amount];
    }

    int changeTabulationSpaceOptimized(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                prev[i] = 1;
            }
        }
        for(int idx = 1; idx < n; idx++) {
            vector<int> curr(amount + 1, 0);
            curr[0] = 1;
            for(int amt = 0; amt <= amount; amt++) {
                int skip = prev[amt];
                int take = 0;
                if(coins[idx] <= amt) {
                    take = curr[amt - coins[idx]];
                }
                curr[amt] = skip + take;
            }
            prev = curr;
        }
        return prev[amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return changeRecursive(n - 1, amount, coins);
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // return changeRecursiveMemo(n - 1, amount, coins, dp);
        // return changeTabulation(amount, coins);
        return changeTabulationSpaceOptimized(amount, coins);
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    cout << Solution().change(5, coins) << endl;
    return 0;
}