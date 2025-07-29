#include <bits/stdc++.h>
using namespace std;

//  Steps
//  1. Reverse the infix expression
//  2. Replace the brackets opening -> closing  and closing -> opening
//  3. Infix to postfix conversion under control conditions
//  4. Reverse the final expression4

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

string Reverse(string s) {
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            s[i] = ')';
        }
        else if(s[i] == ')') {
            s[i] = '(';
        }
    }
    return s;
}

string infix2Prefix(string s) {
    s = Reverse(s);
    int i = 0, n = s.size();
    string ans = "";
    stack<char> stt;

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
            if(s[i] == '^') {
                while(!stt.empty() && priority(s[i]) <= priority(stt.top())) {
                    ans += stt.top();
                    stt.pop();
                }
            } else {
                while(!stt.empty() && priority(s[i]) < priority(stt.top())) {
                    ans += stt.top();
                    stt.pop();
                }
            }
            stt.push(s[i]);
        }
        i++;
    }
    while(!stt.empty()) {
        ans += stt.top();
        stt.pop();
    }
    return Reverse(ans);
}

int main() {
    string s = "abc+def*+";
    cout << infix2Prefix(s) << endl;
    return 0;
}