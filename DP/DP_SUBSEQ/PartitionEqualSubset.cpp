#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // bool canPartitionRecursive(int idx, int sum1, int sum2, vector<int>& nums) {
    //     if(idx < 0) {
    //         return sum1 == sum2;
    //     }

    //     if(canPartitionRecursive(idx - 1, sum1 + nums[idx], sum2, nums)) {
    //         return true;
    //     }

    //     if(canPartitionRecursive(idx - 1, sum1, sum2 + nums[idx], nums)) {
    //         return true;
    //     }
    //     return false;
    // }

    bool canPartitionRecursive(int idx, int target, vector<int>& nums) {
        if(target == 0) {
            return true;
        }
        if(idx == 0) {
            return target == nums[0];
        }

        int notTake = canPartitionRecursive(idx - 1, target, nums);
        int take = false;
        if(target >= nums[idx]) {
            take = canPartitionRecursive(idx - 1, target - nums[idx], nums);
        }
        return take || notTake;
    }

    bool canPartitionMemoization(int idx, int target, vector<int> &nums, vector<vector<int>>& dp) {
        if(target == 0) {
            return true;
        }
        if(idx == 0) {
            return (nums[0] == target);
        }
        if(dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int notTake = canPartitionMemoization(idx-1, target, nums, dp);
        int take = false;
        if(target >= nums[idx]) {
            take = canPartitionMemoization(idx-1, target-nums[idx], nums, dp);
        }
        return dp[idx][target] = take || notTake;
    }

    bool canPartitionTabulation(int target, vector<int>& nums) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        dp[0][nums[0]] = true;
        for(int i = 1; i < n; i++) {
            for(int k = 1; k <= target; k++) {
                bool notTake = dp[i - 1][k];
                bool take = false;
                if(k >= nums[i]) {
                    take = dp[i - 1][k - nums[i]];
                }
                dp[i][k] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }

    bool canPartitionSpaceOptimized(int target, vector<int>& nums) {
        int n = nums.size();
        vector<bool> prev(target + 1, false);
        prev[0] = true;
        for(int i = 0; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for(int k = 1; k <= target; k++) {
                bool notTake = prev[k];
                bool take = false;
                if(k >= nums[i]) {
                    take = prev[k - nums[i]];
                }
                curr[k] = take || notTake;
            }
            prev = curr;
        }
        return prev[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(auto itr : nums) {
            totalSum += itr;
        }
        if(totalSum & 1) {
            return false;
        }
        // return canPartitionRecursive(n - 1, totalSum/2,  nums);
        // vector<vector<int>> dp(n, vector<int>(totalSum/2 + 1, -1));
        // return canPartitionMemoization(n - 1, totalSum/2, nums, dp);
        // return canPartitionTabulation(totalSum/2, nums);
        return canPartitionSpaceOptimized(totalSum/2, nums);

    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1};
    cout << Solution().canPartition(nums) << endl;
    return 0;

}