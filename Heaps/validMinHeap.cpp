#include<bits/stdc++.h>
using namespace std;


bool isHeap(vector<int>& nums){
    for(int i = nums.size()/ 2 - 1; i >=0; i--){
        int lChild = 2*i + 1;
        int rChild = 2*i + 2;

        if(lChild < nums.size() && nums[i] > nums[lChild]) return false;
        if(rChild < nums.size() && nums[i] > nums[rChild]) return false;
    }

    return true;
}

int main(){
    vector<int> nums = {10, 20, 30, 25, 15};
    cout << isHeap(nums) << endl;
    return 0;
}