#include<bits/stdc++.h>
using namespace std;

class Solution{

    private:
    vector<int> heap;

    void heapifyUp(vector<int> &nums, int index){
        if(index> 0){
            int par = (index-1)/2;
            if(nums[index]>nums[par]){
                swap(nums[index], nums[par]);
                heapifyUp(nums, par);
            }
        }
    }

    void heapifyDown(vector<int> &nums, int index){
        int largest = index;
        int lChild = 2*index + 1;
        int rChild = 2*index + 2;

        if(lChild < heapSize() && nums[lChild] > nums[largest]) largest = lChild;
        if(rChild < heapSize() && nums[rChild] > nums[largest]) largest = rChild;

        if(largest != index){
            swap(nums[index], nums[largest]);
            heapifyDown(nums, largest);
        }
    }

    public:

    void initializeHeap(){
        return;
    }

    void insert(int key){
        heap.push_back(key);
        heapifyUp(heap, heap.size() - 1);
    }

    void changeKey(int index, int new_val){
        if(index >= 0 && index < heap.size()){
            if(heap[index] == new_val) return;
            else if(new_val > heap[index]){
                heap[index] = new_val;
                heapifyUp(heap, index);
            }
            else if(new_val < heap[index]){
                heap[index] = new_val;
                heapifyDown(heap, index);
            }
        }
    }

    void extractMax(){
        int max = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(heap, 0);
    }

    bool isEmpty(){
        if(heap.size() == 0) return true;
        else return false;
    }

    int getMax(){
        if(heap.size() > 0){
            return heap[0];
        }
        return -1;
    }

    int heapSize(){
        return heap.size();
    }
};

int main(){
    return 0;
}