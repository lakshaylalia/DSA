#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> stt;
        int n = nums.size();
        for(int i = 2*n-1; i >= 0; i--) {
            while(!stt.empty() && stt.top() <= nums[i%n]) {
                stt.pop();
            }

            if(i < n) {
                int val = stt.empty() ? -1 : stt.top();
                ans.push_back(val);
            }
            stt.push(nums[i%n]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}; 

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> ans = Solution().nextGreaterElements(nums);
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}