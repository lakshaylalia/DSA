#include<bits/stdc++.h>
using namespace std;

void heapifyUp(vector<int> &heap, int idx){
    if(idx > 0){
        int par = (idx - 1)/2;
        if(heap[par] >heap[idx]){
            swap(heap[par], heap[idx]);
            heapifyUp(heap, par);
        }
    }
}

void heapifyDown(vector<int> &heap, int idx){
    int smallest = idx;
    int lChild = 2*idx + 1;
    int rChild = 2*idx + 2;

    if(lChild < heap.size() && heap[lChild] < heap[smallest]) smallest = lChild;
    if(rChild < heap.size() && heap[rChild] < heap[smallest]) smallest = rChild;

    if(smallest != idx){
        swap(heap[idx], heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

void heapify(vector<int> &heap, int idx, int val){
    if(idx < heap.size() && idx >= 0){
        if(heap[idx] == val) return;
        else if(heap[idx] > val){
            heap[idx] = val;
            heapifyUp(heap, idx);
        } else {
            heap[idx] = val;
            heapifyDown(heap, idx);
        }
    }
}

int main(){
    vector<int> minHeap = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    heapify(minHeap, 5, -1);
    for(auto itr :  minHeap) cout << itr << " ";
    return 0;
}