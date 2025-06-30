#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countSub(vector<int> &nums, int goal) {
        if(goal < 0) return 0;

        int cnt = 0;
        int ones = 0, n = nums.size();
        int left = 0;

        for(int right = 0; right < n; right++) {
            if(nums[right]) ones++;

            while(ones > goal) {
                if(nums[left]) ones--;
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSub(nums, goal) - countSub(nums, goal - 1);
    }
};

int main() {
    vector<int> nums = {1,0,1,0,1};
    cout << Solution().numSubarraysWithSum(nums, 2) << endl;
    return 0;
}