#include <bits/stdc++.h>
using namespace std;

void heapifyUp(vector<int> &heap, int idx){
    if(idx > 0){
      int par = (idx - 1)/2;
      if(heap[par] < heap[idx]){
        swap(heap[par], heap[idx]);
        heapifyUp(heap, par);
      }
    }
}


void heapifyDown(vector<int> &heap, int index){
    int largest = index;
    int lChild = 2*index + 1;
    int rChild = 2*index + 2;
    if((lChild < heap.size()) && (heap[lChild] > heap[largest])) largest = lChild;
    if((rChild < heap.size()) && (heap[rChild] > heap[largest])) largest = rChild;
    if(largest != index){
        swap(heap[largest], heap[index]);
        heapifyDown(heap, largest);
    }
}

vector<int> minToMaxHeap(vector<int> nums){
    // vector<int> maxHeap;
    // for(int  i= 0; i < nums.size(); i++){
    //     maxHeap.push_back(nums[i]);
    //     heapifyUp(maxHeap, i);
    // }
    // return maxHeap;

    for(int  i = nums.size() / 2 - 1; i >= 0; i--){
        heapifyDown(nums, i);
    }
    return nums;
}

int main() {
    vector<int> heap = {-5, -4, -3, -2, -1};
    heap = minToMaxHeap(heap);
    for(auto itr : heap) cout << itr << " ";
    return 0;
}