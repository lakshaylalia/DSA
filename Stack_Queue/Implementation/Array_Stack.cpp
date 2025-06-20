#include <bits/stdc++.h>
using namespace std;


class ArrayStack {
private:
   int *Stack;
   int topIdx;
   int maxSize;
public:
    ArrayStack(int size) {
        maxSize = size;
        Stack = new int[size];
        topIdx = -1;
    }
    
    void push(int x) {
        if(topIdx == maxSize - 1) {
            cout << "Stack is full" << endl;
            return;
        }
        topIdx++;
        Stack[topIdx] = x;
    }
    
    int pop() {
        if(topIdx == -1) {
            cout << "Stack is empty" << endl;
            return 10e9;
        }
        return Stack[topIdx--];
    }
    
    int top() {
        if(topIdx == -1) {
            cout << "Stack is empty" << endl;
            return 10e9;
        }
        return Stack[topIdx];
    }

    int size() {
        return topIdx + 1;
    }
    
    bool isEmpty() {
        return topIdx == -1;
    }
};


int main() {
    
    return 0;
}