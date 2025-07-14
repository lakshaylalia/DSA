#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxProfitRecursive(int idx, bool canBuy, int fees, vector<int> &prices) {
        if(idx >= prices.size()) {
            return 0;
        }

        int profit = 0;
        if(canBuy) {
            int buy = -prices[idx] + maxProfitRecursive(idx + 1, false, fees, prices);
            int notBuy = maxProfitRecursive(idx + 1, true, fees, prices);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[idx] - fees + maxProfitRecursive(idx + 1, true, fees, prices);
            int notSell = maxProfitRecursive(idx + 1, false, fees, prices);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int maxProfitMemoization(int idx, bool canBuy, int fees, vector<int> &prices, vector<vector<int>> &dp) {
        if(idx >= prices.size()) {
            return 0;
        }

        if(dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }

        int profit = 0;
        if(canBuy) {
            int buy = -prices[idx] + maxProfitMemoization(idx + 1, false, fees, prices, dp);
            int notBuy = maxProfitMemoization(idx + 1, true, fees, prices, dp);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[idx] - fees + maxProfitMemoization(idx + 1, true, fees, prices, dp);
            int notSell = maxProfitMemoization(idx + 1, false, fees, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfitTabulation(int fee, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for(int i = n-1; i>= 0; i--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    int buy = -prices[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    profit = max(buy, notBuy); 
                } else {
                    int sell = prices[i] - fee + dp[i+1][1];
                    int notSell = dp[i+1][0];
                    profit = max(sell, notSell);
                }
                dp[i][canBuy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfitTabulationSpaceOptimized(int fee, vector<int> &prices) {
        int n  = prices.size();
        vector<int> ahead(2, 0);
        
        for(int i = n-1; i >= 0; i--) {
            vector<int> curr(2, 0);
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    int buy = -prices[i] + ahead[0];
                    int notBuy = ahead[1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = prices[i] - fee + ahead[1];
                    int notSell = ahead[0];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // return maxProfitRecursive(0, true, fee, prices);
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return maxProfitMemoization(0, true, fee, prices, dp);
        // return maxProfitTabulation(fee, prices);
        return maxProfitTabulationSpaceOptimized(fee, prices);
    }
};

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    cout << Solution().maxProfit(prices, 2) << endl;
    return 0;
}