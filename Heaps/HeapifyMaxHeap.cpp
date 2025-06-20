#include<bits/stdc++.h>
using namespace std;

void heapifyDown(vector<int> &heap, int idx){
    int largestIdx = idx;
    int lChild = 2*idx + 1;
    int rChild = 2*idx + 2;

    if(lChild < heap.size() && heap[lChild] > heap[largestIdx]) largestIdx = lChild;
    if(rChild < heap.size() && heap[rChild] > heap[largestIdx]) largestIdx = rChild;
    if(largestIdx != idx){
    swap(heap[idx], heap[largestIdx]);
    heapifyDown(heap, largestIdx);
    }
}





void heapifyUp(vector<int> &heap, int idx){
    if(idx > 0){
        int par = (idx-1)/2;
        if(heap[idx] > heap[par]){
            swap(heap[idx], heap[par]);
            heapifyUp(heap, par);
        }
    }
}

void heapify(vector<int> &heap, int idx, int val){
    if(heap[idx] == val) return;
    if(idx < heap.size() && idx >= 0){
        if(heap[idx] < val){
            heap[idx] = val;
            heapifyUp(heap, idx);      
        } 
        else if(heap[idx] > val){
            heap[idx] = val;
            heapifyDown(heap, idx); 
        }
    }
}


int main(){
    vector<int> maxHeap = {10, 7, 6, 4, 5, 4, 5, 2, 3}; 
    heapify(maxHeap, 0, 1);
    for(auto itr : maxHeap) cout << itr << " ";
    return 0;
}