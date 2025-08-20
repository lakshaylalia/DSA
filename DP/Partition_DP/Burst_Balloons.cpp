#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Recurssive(int i, int j, vector<int> &nums) {
        if(i > j) {
            return 0;
        }
        int maxi = INT_MIN;
        for(int k = i; k <= j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1] + Recurssive(i, k-1, nums) + Recurssive(k+1, j, nums);
            maxi = max(maxi, cost);
        }
        return maxi;
    }

    int Memoization(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int maxi = INT_MIN;
        for(int k = i; k <= j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1] + Memoization(i, k-1, nums, dp) + Memoization(k+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                if(i > j) {
                    continue;
                }
                int maxi = INT_MIN;
                for(int k = i; k <= j; k++) {
                    int cost = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << Solution().maxCoins(nums) << endl;
    return 0;
}