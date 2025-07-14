#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxProfitRecursive(int idx, int k, bool canBuy, vector<int> &prices) {
        if (idx >= prices.size() || k == 0) return 0;

        int profit = 0;
        if (canBuy) {
            int buy = maxProfitRecursive(idx + 1, k, false, prices) - prices[idx];
            int skip = maxProfitRecursive(idx + 1, k, true, prices);
            profit = max(buy, skip);
        } else {
            int sell = maxProfitRecursive(idx + 1, k - 1, true, prices) + prices[idx];
            int skip = maxProfitRecursive(idx + 1, k, false, prices);
            profit = max(sell, skip);
        }
        return profit;
    }

    int maxProfitMemoization(int idx, int k, bool canBuy, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        if(idx >= prices.size() || k == 0) {
            return 0;
        }
        if(dp[idx][canBuy][k] != -1) {
            return dp[idx][canBuy][k];
        }
        int profit = 0;
        if(canBuy) {
            int buy = maxProfitMemoization(idx + 1, k, false, prices, dp) - prices[idx];
            int skip = maxProfitMemoization(idx + 1, k, true, prices, dp);
            profit = max(buy, skip);
        } else {
            int sell = maxProfitMemoization(idx + 1, k - 1, true, prices, dp) + prices[idx];
            int skip = maxProfitMemoization(idx + 1, k, false, prices, dp);
           profit = max(sell, skip);
        }
        return dp[idx][canBuy][k] = profit;
    }

    int maxProfitTabulation(int K, vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int k = 1; k <= K; k++) {
                    int profit = 0;
                    if (canBuy) {
                        int buy = dp[i + 1][0][k] - prices[i];
                        int skip = dp[i + 1][1][k];
                        profit = max(buy, skip);
                    } else {
                        int sell = dp[i + 1][1][k - 1] + prices[i];
                        int skip = dp[i + 1][0][k];
                        profit = max(sell, skip);
                    }
                    dp[i][canBuy][k] = profit;
                }
            }
        }
        return dp[0][1][K];
    }

    int maxProfitTabulationSpaceOptimized(int K, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(K + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(2, vector<int>(K + 1, 0));
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int k = 1; k <= K; k++) {
                    int profit = 0;
                    if (canBuy) {
                        int buy = prev[0][k] - prices[i];
                        int skip = prev[1][k];
                        profit = max(buy, skip);
                    } else {
                        int sell = prev[1][k - 1] + prices[i];
                        int skip = prev[0][k];
                        profit = max(sell, skip);
                    }
                    curr[canBuy][k] = profit;
                }
            }
            prev = curr;
        }
        return prev[1][K];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // return maxProfitRecursive(0, k, true, prices);
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // return maxProfitMemoization(0, k, true, prices, dp);
        // return maxProfitTabulation(k, prices);
        return maxProfitTabulationSpaceOptimized(k, prices);
    }
};


int main() {
    vector<int> prices = {3,2,6,5,0,3};
    cout << Solution().maxProfit(2, prices) << endl;
    return 0;
}