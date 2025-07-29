#include <bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if(ch == '^') {
        return 3;
    } else if(ch == '*' || ch == '/') {
        return 2;
    } else if(ch == '+' || ch == '-') {
        return 1;
    } 
    return -1;
}

string postFix2Infix(string s) {
    stack<string> stt;
    for (char ch : s) {
        if (isalnum(ch)) {
            stt.push(string(1, ch));
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (stt.size() < 2) return "Invalid Expression";
            string op1 = stt.top(); stt.pop();
            string op2 = stt.top(); stt.pop();
            string temp = "(" + op2 + ch + op1 + ")";
            stt.push(temp);
        } else {
            return "Invalid Character in Expression";
        }
    }
    if (stt.size() != 1) return "Invalid Expression";
    return stt.top();
}


int main() {
    string s = "ab+c*";
    cout << postFix2Infix(s) << endl;
    return 0;
}