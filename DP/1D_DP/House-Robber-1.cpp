#include <bits/stdc++.h>
using namespace std;

// House Robber 1
class Solution {
private:
    int maxSumRecurssion(int idx, int sum, vector<int> &nums) {
        if(idx >= nums.size()) {
            return sum;
        }
        int take = maxSumRecurssion(idx + 2, sum + nums[idx], nums);
        int notTake = maxSumRecurssion(idx + 1, sum, nums);
        return max(take, notTake);
    }

    int maxSumMemo(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }
        int take = nums[idx] + maxSumMemo(idx + 2, nums, dp);
        int notTake = maxSumMemo(idx + 1, nums, dp);
        return dp[idx] = max(take, notTake);
    }

    int maxSumTabulation(vector<int> &nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--) {
            int take = nums[i] + dp[i + 2];
            int notTake = dp[i + 1];
            dp[i] = max(take, notTake);
        }

        return dp[0];
    }

    int maxSumSpaceOptimized(vector<int> &nums) {
        int n = nums.size();
        int next = 0, next2 = 0;
        for(int i = n-1; i >= 0; i--) {
            int take = nums[i] + next2;
            int notTake = next;
            next2 = next;
            next = max(take, notTake);
        }
        return next;
    }

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        // return maxSumRecurssion(0, 0, nums);
        // return maxSumMemo(0, nums, dp);
        // return maxSumTabulation(nums);
        return maxSumSpaceOptimized(nums);
    }
};

int main() {
    vector<int> nums = {2, 1, 4, 9};
    cout << Solution().rob(nums) << endl;
    return 0;
}