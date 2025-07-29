#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> Tabulation(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i = 1; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;    
            }
        }
        int i = lastIndex;
        vector<int> ans;
        while(hash[i] != i) {
            ans.push_back(nums[i]);
            i = hash[i];
        }
        ans.push_back(nums[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        return Tabulation(arr);
    }
};

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    vector<int> ans = Solution().longestIncreasingSubsequence(arr);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}