#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size(); i++){
            if( i > farthest) return false;
            if(farthest >= nums.size()) return true;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};

int main() {
    vector<int> nums = {3,2,1,1,4};
    cout << Solution().canJump(nums) << endl;
    return 0;
}