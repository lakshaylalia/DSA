#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int largest(int i, int j, vector<int>& arr) {
    //     int maxi = INT_MIN;
    //     for (int k = i; k <= j; k++) {
    //         maxi = max(maxi, arr[k]);
    //     }
    //     return maxi;
    // }

    // int func(int i, int k, vector<int>& arr, vector<int>& dp) {
    //     if (i == arr.size()) {
    //         return 0;
    //     }
    //     if (dp[i] != -1) {
    //         return dp[i];
    //     }
    //     int maxi = INT_MIN;
    //     for (int j = i; j < arr.size(); j++) {
    //         if ((j - i + 1) <= k) {
    //             int val = largest(i, j, arr) * (j - i + 1);
    //             val += func(j + 1, k, arr, dp);
    //             maxi = max(maxi, val);
    //         }
    //     }
    //     return dp[i] = maxi;
    // }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int currMax = INT_MIN;
            int best = INT_MIN;
            for (int j = i; j < min(n, i + k); j++) {
                currMax = max(currMax, arr[j]);
                int val = currMax * (j - i + 1) + dp[j + 1];
                best = max(best, val);
            }
            dp[i] = best;
        }
        return dp[0];
    }
};

int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    cout << Solution().maxSumAfterPartitioning(arr, 3);
    return 0;
}