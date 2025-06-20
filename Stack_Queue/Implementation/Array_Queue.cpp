#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
private:
    int start, end, capacity;
    int *Queue;

public:
    ArrayQueue(int size) {
        capacity = size;
        Queue = new int[capacity];
        start = -1;
        end = -1;
    }

    void push(int x) {
        if ((end + 1) % capacity == start) {
            cout << "Queue is full, Overflow" << endl;
            return;
        }
        if (start == -1) start = 0;
        end = (end + 1) % capacity;
        Queue[end] = x;
    }

    int pop() {
        if (start == -1) {
            cout << "Queue is empty, Underflow" << endl;
            return 1e9;
        }
        int result = Queue[start];
        if (start == end) {
            start = end = -1;
        } else {
            start = (start + 1) % capacity;
        }
        return result;
    }

    int front() {
        if (start == -1) {
            cout << "Queue is empty, Underflow" << endl;
            return 1e9;
        }
        return Queue[start];
    }

    int size() {
        if (start == -1) return 0;
        if (end >= start)
            return end - start + 1;
        return capacity - (start - end - 1);
    }

    bool isEmpty() {
        return start == -1;
    }
};

int main() {
    
    return 0;
}