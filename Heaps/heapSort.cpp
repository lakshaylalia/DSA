#include <bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int> &nums, int idx,  int heapSize) {
        int largest = idx;
        int lChild = 2 * idx + 1;
        int rChild = 2 * idx + 2;

        if (lChild < heapSize && nums[lChild] > nums[largest]) largest = lChild;
        if (rChild < heapSize && nums[rChild] > nums[largest]) largest = rChild;

        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            heapifyDown(nums, largest, heapSize);
        }
    }

    void heapSort(vector<int> &nums) {
        int n = nums.size();
        for(int i = nums.size() / 2 - 1; i >= 0; i--){
            heapifyDown(nums, i, n);
        }

        for(int i = nums.size() - 1; i >=0; i--){
            swap(nums[0], nums[i]);
            heapifyDown(nums, 0, i);
        }
    }

int main() {
    vector<int> nums= {7, 4, 1, 5, 3};
    heapSort(nums);
    for(auto itr : nums) cout << itr << " ";
    return 0;
}