#include <bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     int findTargetSumWaysRecursive(int idx, int target, vector<int> &nums) {
//         int n = nums.size();
//         if(idx == n) {
//             if(target == 0) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }
//         if(target <= 0) {
//             return 0;
//         }
//         int positive = findTargetSumWaysRecursive(idx + 1, target - nums[idx], nums);
//         int negative = findTargetSumWaysRecursive(idx + 1, target + nums[idx], nums);
//         return positive + negative;
//     }

//     int findTargetSumWaysRecursiveMemoization(int idx, int target, vector<int> &nums, map<pair<int,int>, int> &dp) {
//         int n = nums.size();
//         if (idx == n) {
//             if (target == 0) {
//                 return 1;
//             } else {
//                 return 0;
//             }
//         }

//         if (dp.count({idx, target})) {
//             return dp[{idx, target}];
//         }

//         int positive = findTargetSumWaysRecursiveMemoization(idx + 1, target - nums[idx], nums, dp);
//         int negative = findTargetSumWaysRecursiveMemoization(idx + 1, target + nums[idx], nums, dp);

//         return dp[{idx, target}] = positive + negative;
//     }

// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size();
//         // return findTargetSumWaysRecursive(0, target, nums);
//         map<pair<int,int>, int> dp;
//         return findTargetSumWaysRecursiveMemoization(0, target, nums, dp);
//     }
// };

class Solution {
private:
    int subsetWays(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> prev(target + 1, 0);
        if(nums[0] == 0) {
            prev[0] = 2;
        } else {
            prev[0] = 1;
        }
        if(nums[0] != 0 && nums[0] <= target) {
            prev[nums[0]] = 1;
        }

        for(int idx = 1; idx < n; idx++) {
            vector<int> curr(target + 1, 0);
            for(int k = 0; k <= target; k++) {
                int skip = prev[k];
                int pick = 0;
                if(nums[idx] <= k) {
                    pick = prev[k-nums[idx]];
                }
                curr[k] = pick + skip;
            }
            prev = curr;
        }
        return prev[target];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int toatlSum = accumulate(nums.begin(), nums.end(), 0);
        int negSum = (toatlSum - target);
        if(negSum < 0 || negSum & 1) {
            return 0;
        }
        negSum /= 2;
        return subsetWays(negSum, nums);
    }
};

int main() {
    vector<int> nums = {1, 2, 7, 1, 5};
    cout << Solution().findTargetSumWays(nums, 4)<< endl;
    return 0;
}