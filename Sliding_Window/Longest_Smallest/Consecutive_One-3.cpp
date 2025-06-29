#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int zeros = 0;
        int maxLen = 0;
        while(right < n) {
            if(nums[right] == 0) {
                zeros++;
            }
            if(zeros > k) {
                if(nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            if(zeros <= k) {
                maxLen = max(maxLen, right-left+1);
            }
            right++;
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left = 0, right = 0;
//         int len = 0, maxLen = 0;
//         while(right < n) {
//             if(nums[right] == 1) {
//                 right++;
//                 len++;
//             } else if(nums[right] == 0 && k > 0) {
//                 right++;
//                 k--;
//                 len++;
//             } else {
//                 while(nums[left] == 1) {
//                     left++;
//                     len--;
//                 }
//                 left++;
//                 len--;
//                 k++;
//             }
//             maxLen = max(maxLen, len);
//         }
//         return maxLen;
//     }
// };

int main() {
    vector<int> nums = {1, 1, 0, 0, 1};
    cout << Solution().longestOnes(nums, 3) << endl;
    return 0;
}