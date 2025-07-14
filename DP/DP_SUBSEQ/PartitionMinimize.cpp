#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // int minimumDifferenceRecursive(int idx, int len, int sum, int target, vector<int> &nums) {
    //     int n = nums.size();
    //     if(len > n/2) {
    //         return 1e9;
    //     }
    //     if(idx >= n) {
    //         if(len == n/2) {
    //             return abs(target - sum) * 2;
    //         }
    //         return 1e9;
    //     }

    //     int take = minimumDifferenceRecursive(idx+1, len+1, sum+nums[idx], target, nums);
    //     int skip = minimumDifferenceRecursive(idx+1, len, sum, target, nums);
    //     return min(take, skip);
    // }

public:
int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        vector<bool> prev(totSum + 1, false);

        prev[0] = true;

        if (nums[0] <= totSum)
            prev[nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {

            vector<bool> cur(totSum + 1, false);
            
            cur[0] = true;

            for (int target = 1; target <= totSum; target++) {
                bool notTaken = prev[target];
                bool taken = false;
                if (nums[ind] <= target)
                    taken = prev[target - nums[ind]];

                cur[target] = notTaken || taken;
            }
            prev = cur;
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) {
            if (prev[i] == true) {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};
int main() {
    vector<int> nums = {3, 9, 7, 3};
    cout << Solution().minimumDifference(nums) << endl;
    return 0;
}