#include <bits/stdc++.h>
using namespace std;

string postfix2Prefix(string s) {
    int i = 0, n = s.size();
    stack<string> stt;
    while(i < n) {
        if(isalpha(s[i]) || isdigit(s[i])) {
            stt.push(string(1, s[i]));
        } else {
            string op1 = stt.top(); stt.pop();
            string op2 = stt.top(); stt.pop();
            stt.push(s[i]+op2+op1);
        }
        i++;
    }
    return stt.top();
}

int main() {
    
    return 0;
}