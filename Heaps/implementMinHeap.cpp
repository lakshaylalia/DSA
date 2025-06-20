#include<bits/stdc++.h>
using namespace std;


class Heap{
    private:
   vector<int> heap;

   void heapifyDown(vector<int> &heap, int index){
    int smallest = index;
    int lChild = 2*index + 1;
    int rChild = 2*index + 2;

    if(lChild < heap.size() && heap[lChild] < heap[smallest]) smallest = lChild;
    if(rChild < heap.size() && heap[rChild] < heap[smallest]) smallest = rChild;

    if(smallest != index){
        swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest);
    }
   }

   void heapifyUp(vector<int> &heap, int index){
    if(index > 0){
        int par = (index - 1)/2;

        if(heap[par] > heap[index]){
            swap(heap[index], heap[par]);
            heapifyUp(heap, par);
        }
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
            else if(heap[index] < new_val){
                heap[index] = new_val;
                heapifyDown(heap, index);
            }
            else{
                heap[index] = new_val;
                heapifyUp(heap, index);
            }
        }
    }

    void extractMin(){
        if(heap.size() > 0){
            int min = heap[0];
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(heap, 0);
        }
    }

    bool isEmpty(){
        if (heap.size() == 0) return true ;
        return false;
    }
    
    int getMin(){
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