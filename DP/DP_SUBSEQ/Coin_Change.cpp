#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int coinChangeRecursive(int idx, int amount, vector<int> &coins) {
        if(amount == 0) {
            return 0;
        }

        if(idx == 0) {
            if(amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return 1e9;
        }

        int skip = coinChangeRecursive(idx-1, amount, coins);
        int take = INT_MAX;
        if(amount >= coins[idx]) {
            take = 1 + coinChangeRecursive(idx, amount - coins[idx], coins);
        }
        return min(skip, take);
    }

    int coinChangeMemoization(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(amount == 0) {
            return 0;
        }

        if(idx == 0) {
            if(amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return 1e9;
        }

        if(dp[idx][amount] != -1)  {
            return dp[idx][amount];
        }

        int skip = coinChangeMemoization(idx-1, amount, coins, dp);
        int take = INT_MAX;
        if(amount >= coins[idx]) {
            take = 1 + coinChangeMemoization(idx, amount - coins[idx], coins, dp);
        }
        return dp[idx][amount] = min(skip, take);
    }

    int maxCoinsTabulation(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for(int i = 0; i <= amount; i++) {
        if(i % coins[0] == 0) {
            dp[0][i] = i / coins[0];
        } else {
            dp[0][i] = 1e9;
        }
    }

    for(int idx = 1; idx < n; idx++) {
        for(int amt = 0; amt <= amount; amt++) {
            int skip = dp[idx-1][amt];
            int take = 1e9;
            if(amt >= coins[idx]) {
                take = 1 + dp[idx][amt - coins[idx]];
            }
            dp[idx][amt] = min(skip, take);
        }
    }

    return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
}


    int maxCoinsTabulationSpaceOptimized(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                prev[i] = i / coins[0];
            } else {
                prev[i] = 1e9;
            }
        }

        for(int idx = 1; idx < n; idx++) {
            vector<int> curr(amount + 1, 0);
            for(int amt = 0; amt <= amount; amt++) {
                int skip = prev[amt];
                int take = INT_MAX;
                if(amt >= coins[idx]) {
                    take = 1 + prev[amt - coins[idx]];
                }
                curr[amt] = min(skip, take);
            }
            prev = curr;
        }
        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};

class Solution {
private:
    int coinChangeRecursive(int amount, vector<int> &coins) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return 1e9;
        }

        int ans = INT_MAX;
        for (auto itr : coins) {
            int res = 1 + coinChangeRecursive(amount - itr, coins);
            ans = min(ans, res);
        }
        return ans;
    }

    int coinChangeMemoization(int amount, vector<int> &coins, vector<int> &dp) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return 1e9;
        }

        if (dp[amount] != -1)  {
            return dp[amount];
        }
        
        int ans = INT_MAX;
        for (auto itr : coins) {
            int res = 1 + coinChangeMemoization(amount - itr, coins, dp);
            ans = min(ans, res);
        }
        return dp[amount] = ans;
    }

    int maxCoinsTabulation(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto itr : coins) {
                if(i - itr >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - itr]);
                }
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        // return coinChangeRecursive(amount, coins);
        // vector<int> dp(amount + 1, -1);
        // return coinChangeMemoization(amount, coins, dp);
        return maxCoinsTabulation(coins, amount);
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    cout << Solution().coinChange(coins, 11);
    return 0;
}