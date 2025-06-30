#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int countSub(vector<int> &nums, int k) {
        if(k < 0) {
            return 0;
        }
        int n = nums.size();
        int count = 0, total = 0;
        int left = 0, right = 0;
        while(right < n) {
            if(nums[right] & 1) {
                total++;
            }
            while(total > k) {
                if(nums[left] & 1) {
                    total--;
                }
                left++;
            }
            if(total <= k) {
                count += right-left+1;
            }
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSub(nums, k) - countSub(nums,k-1);
    }
};

int main() {
    vector<int> nums = {1,1,2,1,1};
    cout << Solution().numberOfSubarrays(nums, 3) << endl;
    return 0;
}