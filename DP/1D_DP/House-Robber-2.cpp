#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   int maxAmountRecursion(int idx, int sum, int n, vector<int>& nums) {
    if(idx >= n) {
        return sum;
    }
    int take = maxAmountRecursion(idx + 2, sum + nums[idx], n, nums);
    int notTake = maxAmountRecursion(idx + 1, sum, n, nums);
    return max(take, notTake);
   }

   int maxAmountMemoization(int idx, int n, vector<int>& nums, vector<int> &dp) {
    if(idx >= n) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }
    int take = nums[idx] +  maxAmountMemoization(idx + 2, n, nums, dp);
    int notTake = maxAmountMemoization(idx + 1, n, nums, dp);
    return dp[idx] = max(take, notTake);
   }

   int maxAmountTabulation(int start, int n, vector<int>& nums) {
    vector<int> dp(n+2, 0);
    for(int i = n-1; i >= start; i--) {
        int take = nums[i] + dp[i+2];
        int notTake = dp[i+1];
        dp[i] = max(take, notTake);
    }
    return dp[start];
   }

   int maxAmountTabulationSpaceOptimized(int start, int n, vector<int>& nums) {
    int next = 0, next2 = 0;
    for(int i = n-1; i >= start; i--) {
        int take = nums[i] + next2;
        int notTake = next;
        next2 = next;
        next = max(take, notTake);
    }
    return next;
   }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // int first = maxAmountRecursion(0, 0, n-1, nums);
        // int second = maxAmountRecursion(1, 0, n, nums);
        // int first = maxAmountMemoization(0, n-1, nums, dp);
        // int second = maxAmountMemoization(1, n, nums, dp);
        // int first = maxAmountTabulation(0, n-1, nums);
        // int second = maxAmountTabulation(1, n, nums);
        int first = maxAmountTabulationSpaceOptimized(0, n-1, nums);
        int second = maxAmountTabulationSpaceOptimized(1, n, nums);
        return max(first, second);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << Solution().rob(nums) << endl;
    return 0;
}