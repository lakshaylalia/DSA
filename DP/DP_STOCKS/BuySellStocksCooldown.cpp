#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int maxProfitRecursion(int idx, bool canBuy, vector<int>& prices) {
        if(idx >= prices.size()) {
            return 0;
        }

        int profit = 0;
        if(canBuy) {
            int buy = -prices[idx] + maxProfitRecursion(idx+1, false, prices);
            int notBuy = maxProfitRecursion(idx+1, true, prices);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[idx] + maxProfitRecursion(idx+2, true, prices);
            int notSell = maxProfitRecursion(idx+1, false, prices);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int maxProfitRecursion(int idx, bool canBuy, vector<int>& prices, vector<vector<int>>& dp) {
        if(idx >= prices.size()) {
            return 0;
        }

        if(dp[idx][canBuy] != -1) {
            return dp[idx][canBuy];
        }

        int profit = 0;
        if(canBuy) {
            int buy = -prices[idx] + maxProfitRecursion(idx+1, false, prices, dp);
            int notBuy = maxProfitRecursion(idx+1, true, prices, dp);
            profit = max(buy, notBuy);
        } else {
            int sell = prices[idx] + maxProfitRecursion(idx+2, true, prices, dp);
            int notSell = maxProfitRecursion(idx+1, false, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[idx][canBuy] = profit;
    }

    int maxProfitTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int i = n-1; i >= 0; i--) {
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    int buy = -prices[i] + dp[i+1][0];
                    int notBuy = dp[i+1][1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = prices[i] + dp[i+2][1];
                    int notSell = dp[i+1][0];
                    profit = max(sell, notSell);
                }
                dp[i][canBuy] = profit;
            }
        }
        return dp[0][1];
    }

    int maxProfitTabulationSpaceOptimized(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), ahead2(2, 0);
        for(int i = n-1; i >= 0; i--) {
            vector<int> curr(2, 0);
            for(int canBuy = 0; canBuy <= 1; canBuy++) {
                int profit = 0;
                if(canBuy) {
                    int buy = -prices[i] + ahead[0];
                    int notBuy = ahead[1];
                    profit = max(buy, notBuy);
                } else {
                    int sell = prices[i] + ahead2[1];
                    int notSell = ahead[0];
                    profit = max(sell, notSell);
                }
                curr[canBuy] = profit;
            }
            ahead2 = ahead;
            ahead = curr;
        }
        return ahead[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // return maxProfitRecursion(0, true, prices);
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return maxProfitRecursion(0, true, prices, dp);
        // return maxProfitTabulation(prices);
        return maxProfitTabulationSpaceOptimized(prices);
    }
};

int main() {
    vector<int> prices = {1,2,3,0,2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}