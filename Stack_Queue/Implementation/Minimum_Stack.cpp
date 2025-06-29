#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<long long> stt;
    long long minVal;
public:

    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        if(stt.empty()) {
            stt.push(val);
            minVal = val;
        } else {
            if(val >= minVal) {
                stt.push(val);
            } else {
                long long newVal = 2LL * val - minVal;
                stt.push(newVal);
                minVal = val;
            }
        }
    }
    
    void pop() {
        long long val = stt.top();
        stt.pop();
        if(val < minVal) {
            minVal = 2LL * minVal - val;
        }
    }
    
    int top() {
        long long val = stt.top();
        if(val < minVal) return minVal;
        return val;
    }
    
    int getMin() {
        return minVal;
    }
};


int main() {
    
    return 0;
}