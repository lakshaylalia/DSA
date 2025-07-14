#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int minVal = prices[0], profit = 0;
//         for(int i = 1; i < n; i++) {
//             profit = max(profit, prices[i]-minVal);
//             minVal = min(minVal, prices[i]);
//         }
//         return profit;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxPofit = 0;
        int mini = prices[0];
        for(int i = 1; i < n; i++) {
            maxPofit = max(maxPofit, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return maxPofit;
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}