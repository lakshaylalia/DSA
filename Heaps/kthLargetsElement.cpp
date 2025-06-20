#include <bits/stdc++.h>
using namespace std;

// Brute
void heapifyDown(vector<int> &heap, int idx){
    int largest = idx;
    int lChild = 2*idx + 1;
    int rChild = 2*idx + 2;

    if(lChild < heap.size() && heap[lChild] > heap[largest]) largest = lChild;
    if(rChild < heap.size() && heap[rChild] > heap[largest]) largest = rChild;
    if(largest != idx){
    swap(heap[idx], heap[largest]);
    heapifyDown(heap, largest);
    }
}

void buildHeap(vector<int> &nums){
    for(int i = nums.size()/ 2 - 1; i>=0; i--){
        heapifyDown(nums, i);
    }
}

int kthLargestElement1(vector<int>& nums, int k){

    buildHeap(nums);

    while(k - 1 > 0){
        swap(nums[0], nums[nums.size()-1]);
        nums.pop_back();
        heapifyDown(nums, 0);
        k--;
    }

    return nums[0];
}


// Better
int kthLargestElement2(vector<int> &nums, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < k; i++) pq.push(nums[i]);

    for(int i = k; i < nums.size(); i++){
        if(pq.top() < nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}


// Optimal
int randomIndex(int left, int right){
    int len = right - left + 1;
    return (rand() % len) + left;
}


int partitionAndReturnIndex(vector<int> &nums, int pIndex, int left, int right) {
        int pivot = nums[pIndex];
        
        swap(nums[left], nums[pIndex]);
        int ind = left + 1;

        for(int i = left + 1; i <= right; i++) {
            if(nums[i] > pivot) {
                swap(nums[ind], nums[i]);
                ind++;
            }
        }    
        swap(nums[left], nums[ind-1]);   
        return ind - 1;
    }

int kthLargestElement3(vector<int> &nums, int k){
    int left = 0, right = nums.size() - 1;
    if(k > nums.size()) return -1;

    while(true){
        int pIndex = randomIndex(left, right);
        pIndex = partitionAndReturnIndex(nums, pIndex, left, right);

       if(pIndex == k- 1) return nums[pIndex];
       else if(pIndex > k - 1){
        right = pIndex - 1;
       }
       else {
        left = pIndex + 1;
       }
    }
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << kthLargestElement3(nums, k) << endl;
    return 0;
}