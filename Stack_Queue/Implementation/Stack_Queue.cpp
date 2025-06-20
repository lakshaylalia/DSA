#include <bits/stdc++.h>
using namespace std;

class StackQueue {
private:
    stack <int> st1, st2;

public: 
    
    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; 
        }
        int topElement = st1.top();
        st1.pop(); 
        return topElement;
    }
    
    int front() {
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1;
        }
        return st1.top();
    }

    bool isEmpty() {
        return st1.empty();
    }
};




// class StackQueue {
//   public:
//     stack<int> input, output;
//     void push(int x) {
//         input.push(x);
//     }

//     int pop() {
//         if (output.empty()) {
//             while (!input.empty()) {
//                 output.push(input.top());
//                 input.pop();
//             }
//         }
//         if (output.empty()) {
//             cout << "Queue is empty, cannot pop." << endl;
//             return -1;
//         }

//         int x = output.top();
//         output.pop();
//         return x;
//     }

//     int front() {
//         if (output.empty()) {
//             while (!input.empty()) {
//                 output.push(input.top());
//                 input.pop();
//             }
//         }

//         if (output.empty()) {
//             cout << "Queue is empty, cannot peek." << endl;
//             return -1;
//         }

//         return output.top();
//     }

//     bool isEmpty() {
//         return input.empty() && output.empty();
//     }
// };

int main() {
    
    return 0;
}