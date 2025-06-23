#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stt;
        for(int i = n-1; i >= 0; i--) {
            while(!stt.empty() && nums[stt.top()] >= nums[i]) {
                stt.pop();
            }
            ans[i] = stt.empty() ? n : stt.top();
            stt.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerEqualElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stt;
        for(int i = 0; i < n; i++) {
            while(!stt.empty() && nums[stt.top()] > nums[i]) {
                stt.pop();
            }
            ans[i] = stt.empty() ? -1 : stt.top();
            stt.push(i);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stt;
        for(int i = n-1; i >= 0; i--) {
            while(!stt.empty() && nums[stt.top()] <= nums[i]) {
                stt.pop();
            }
            ans[i] = stt.empty() ? n : stt.top();
            stt.push(i);
        }
        return ans;
    }

    vector<int> prevGreaterEqualElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stt;
        for(int i = 0; i < n; i++) {
            while(!stt.empty() && nums[stt.top()] < nums[i]) {
                stt.pop();
            }
            ans[i] = stt.empty() ? -1 : stt.top();
            stt.push(i);
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = nextSmallerElement(nums);
        vector<int> psee = prevSmallerEqualElement(nums);
        vector<int> nge = nextGreaterElement(nums);
        vector<int> pgee = prevGreaterEqualElement(nums);
        int minSum = 0, maxSum = 0;
       for(int i = 0; i < n; i++) {
        int rightSamller = nse[i] - i;
        int leftSamller = i - psee[i];
        minSum = minSum + (rightSamller * leftSamller * nums[i]);
        int rightGreater = nge[i] - i;
        int leftGreater = i - pgee[i];
        maxSum = maxSum + (rightGreater * leftGreater * nums[i]);
       }
       return maxSum - minSum;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    cout << Solution().subArrayRanges(nums) << endl;
    return 0;
}