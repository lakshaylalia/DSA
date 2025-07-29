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

string infix2Postfix(string s) {
    int n = s.size();
    stack<char> stt;
    string ans = "";
    int i = 0;
    while(i < n) {
        if(isalpha(s[i]) || isdigit(s[i])) {
            ans += s[i];
        } else if(s[i] == '(') {
            stt.push(s[i]);
        } else if(s[i] == ')') {
            while(!stt.empty() && stt.top() != '(') {
                ans += stt.top();
                stt.pop();
            }
            stt.pop();
        } else {
            while(!stt.empty() && priority(s[i]) <= priority(stt.top())) {
                ans += stt.top();
                stt.pop();
            }
            stt.push(s[i]);
        }
        i++;
    }
    while(!stt.empty()) {
        ans += stt.top();
        stt.pop();
    }
    return ans;
}

int main() {
    string s = "((a+b)*c)-d";
    cout << infix2Postfix(s) << endl;
    return 0;
}