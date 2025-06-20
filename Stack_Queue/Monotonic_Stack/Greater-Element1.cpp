#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> stt;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stt.empty() && stt.top() <= nums2[i]) {
                stt.pop();
            }
            mpp[nums2[i]] = stt.empty() ? -1 : stt.top();
            stt.push(nums2[i]);
        }
        
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mpp[num]);
        }
        
        return ans;
    }
};


int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int > result = Solution().nextGreaterElement(nums1, nums2);
    for(auto itr : result) {
        cout << itr << " ";
    }
    return 0;
}