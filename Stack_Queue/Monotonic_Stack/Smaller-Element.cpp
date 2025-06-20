#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>  nextSmallerElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        stack<int> stt;

        for(int i = n-1; i >= 0; i--) {
            while(!stt.empty() && stt.top() >= nums[i]) {
                stt.pop();
            }

            int el = stt.empty() ? -1 : stt.top();
            ans.push_back(el);
            stt.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    vector<int> ans = Solution().nextSmallerElement(nums);
    for(auto itr : ans) {
        cout << itr << " "; 
    }
    return 0;
}