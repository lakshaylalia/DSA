#include<bits/stdc++.h>
using namespace std;


void heapifyMinHeap(vector<int> &nums, int i){
        if(i  < nums.size()){
        int smallest = i;
        int lChild = 2 * i + 1;
        int rChild = 2 * i + 2;

        if(lChild < nums.size() && nums[lChild] < nums[smallest]) smallest = lChild;
        if(rChild < nums.size() && nums[rChild] < nums[smallest]) smallest = rChild;

        if(smallest != i){
            swap(nums[i], nums[smallest]);
            heapifyMinHeap(nums, smallest);
        }
    }
}


void heapifyMaxHeap(vector<int> &nums, int i){
    if(i  < nums.size()){
        int largest = i;
        int lChild = 2 * i + 1;
        int rChild = 2 * i + 2;

        if(lChild < nums.size() && nums[lChild] > nums[largest]) largest = lChild;
        if(rChild < nums.size() && nums[rChild] > nums[largest]) largest = rChild;

        if(largest != i){
            swap(nums[i], nums[largest]);
            heapifyMaxHeap(nums, largest);
        }
    }
}


void maxHeap(vector<int> &nums){
    for(int i = nums.size()/ 2 - 1; i >=0; i--){
        heapifyMaxHeap(nums, i);
    }
}


void minHeap(vector<int> &nums){
    for(int i = nums.size()/ 2 - 1; i >=0; i--){
        heapifyMinHeap(nums, i);
    }
}



int main(){
    vector<int> nums = {0,7,6,15,10,11,1,3};
    maxHeap(nums);
    for(auto itr : nums) cout << itr << " ";
    return 0;
}