#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxProfitRecursive(int idx, bool canBuy, vector<int>& prices) {
        if(idx >= prices.size()) {
            return 0;
        }
        int profit = 0;

        if(canBuy) {
            int buy = maxProfitRecursive(idx + 1, false, prices) - prices[idx];
            int notBuy = maxProfitRecursive(idx + 1, true, prices);
            profit = max(buy, notBuy);
        } else {
            int sell = maxProfitRecursive(idx + 1, true, prices) + prices[idx];
            int notSell = maxProfitRecursive(idx + 1, false, prices);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int maxProfitMemoization(int idx, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {

        if(idx >= prices.size()) {
            return 0;
        }

        if(dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }
    
        int profit = 0;
        if(canBuy) {
            int buy = maxProfitMemoization(idx + 1, false, prices, dp) - prices[idx];
            int notBuy = maxProfitMemoization(idx + 1, true, prices, dp);
            profit = max(buy, notBuy);
    
        } else { 
            int sell = maxProfitMemoization(idx + 1, true, prices, dp) + prices[idx];
            int notSell = maxProfitMemoization(idx + 1, false, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfitTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;
        
        int profit;
        for(int i = n-1; i >= 0; i--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy) {
                    int buy = dp[i + 1][0] - prices[i];
                    int notBuy = dp[i + 1][1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = dp[i + 1][1] + prices[i];
                    int notSell = dp[i + 1][0];
                    profit = max(sell, notSell);
                }
                dp[i][canBuy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfitTabulationSpaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0);

        int profit;
        for(int i = n-1; i >= 0; i--) {
            vector<int> curr(2, 0);
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                if(canBuy) {
                    int buy = ahead[0] - prices[i];
                    int notBuy = ahead[1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = ahead[1] + prices[i];
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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return maxProfitRecursive(0, true, prices);
        // return maxProfitMemoization(0, true, prices, dp);
        // return maxProfitTabulation(prices);
        return maxProfitTabulationSpaceOptimized(prices);
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}