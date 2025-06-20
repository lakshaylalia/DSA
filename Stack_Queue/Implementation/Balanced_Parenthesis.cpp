#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stt;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stt.push(s[i]);
            } 
            else if(stt.empty()) {
                return false;
            }
            else if (s[i] == ')') {
                if (stt.top() != '(')
                    return false;
                else
                    stt.pop();
            } 
            else if (s[i] == ']') {
                if (stt.top() != '[')
                    return false;
                else
                    stt.pop();
            } 
            else {
                if (stt.top() != '{')
                    return false;
                else
                    stt.pop();
            }
        }
        return stt.empty();
    }
};

int main() {
    string s  = "{{[)]}}";
    cout << Solution().isValid(s);
    return 0;
}