#include <bits/stdc++.h>
using namespace std;

string prefix2POstfix(string s) {
    int n = s.size();
    int i = n-1;
    stack<string> stt;
    while(i >= 0) {
        if(isalpha(s[i]) || isdigit(s[i])) {
            stt.push(string(1, s[i]));
        } else {
            string op1 = stt.top(); stt.pop();
            string op2 = stt.top(); stt.pop();
            stt.push(op1 + op2 + s[i]);
        }
    }
    return stt.top();
}

int main() {
    
    return 0;
}