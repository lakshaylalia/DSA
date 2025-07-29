#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i]) {
                    if(dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev];
                    } else if(dp[prev] + 1 == dp[i]) {
                        count[i] += count[prev];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) {
                ans += count[i];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,3,5,4,7};
    cout << Solution().findNumberOfLIS(nums) << endl;
    return 0;
}