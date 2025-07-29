#include <bits/stdc++.h>
using namespace std;
class Solution {
private: 
    // int Recursive(int idx, int prevIdx, vector<int> &nums) {
    //     if(idx == 0) {
    //        if(prevIdx == -1 || nums[idx] < nums[prevIdx]) {
    //         return 1;
    //        } else {
    //         return 0;
    //        }
    //     }
    //     int skip = Recursive(idx-1, prevIdx, nums);
    //     int take = 0;
    //     if(prevIdx == -1 || nums[idx] < nums[prevIdx]) {
    //         take = 1 + Recursive(idx-1, idx, nums);
    //     }
    //     return max(skip, take);
    // }
    
    // int Memoization(int idx, int prevIdx, vector<int> &nums, vector<vector<int>> &dp) {
    //     if(idx == 0) {
    //         if(prevIdx == -1 || nums[0] < nums[prevIdx]) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }

    //     if(dp[idx][prevIdx+1] != -1) {
    //         return dp[idx][prevIdx+1];
    //     }

    //     int skip = Memoization(idx-1, prevIdx, nums, dp);
    //     int take = 0;
    //     if(prevIdx == -1 || nums[idx] < nums[prevIdx]) {
    //         take = 1 + Memoization(idx-1, idx, nums, dp);
    //     }
    //     return dp[idx][prevIdx+1] = max(skip, take);
    // }

    int Recursive(int idx, int prevIdx, vector<int> &nums) {
        if(idx >= nums.size()) {
           return 0;
        }
        int skip = Recursive(idx+1, prevIdx, nums);
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + Recursive(idx+1, idx, nums);
        }
        return max(skip, take);
    }

    int Memoization(int idx, int prevIdx, vector<int> &nums, vector<vector<int>> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx][prevIdx+1] != -1) {
            return dp[idx][prevIdx+1];
        }

        int skip = Memoization(idx+1, prevIdx, nums, dp);
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + Memoization(idx+1, idx, nums, dp);
        }
        return dp[idx][prevIdx+1] = max(skip, take);
    }

    int Tabulation(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev_idx = idx-1; prev_idx >= -1; prev_idx--) {
                int skip = dp[idx+1][prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    take = 1 + dp[idx+1][idx+1];
                }
                dp[idx][prev_idx+1] = max(skip, take);
            }
        }
        return dp[0][0];
    }

    int Tabulation2(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 1; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }


    int SpaceOptimization(vector<int> &nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--) {
            for(int prev_idx = idx-1; prev_idx >= -1; prev_idx--) {
                int skip = next[prev_idx+1];
                int take = 0;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    take = 1 + next[idx+1];
                }
                curr[prev_idx+1] = max(skip, take);
            }
            curr = next;
        }
        return curr[0];
    }

    


public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return Recursive(0, -1, nums);
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return Memoization(0, -1, nums, dp);
        int len = 1;
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums) << endl;
    return 0;
}