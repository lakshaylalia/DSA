#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stt;
        for(auto itr : expression) {
            if(itr == ')') {
                char operand = stt.top();
                bool isTrue = false, isFalse = false;
                while(stt.top() != '(') {
                    if(stt.top() == 'f') {
                        isFalse = true;
                    }
                    if(stt.top() == 't') {
                        isTrue = true;
                    }
                    stt.pop();
                }
                stt.pop();
                char oper = stt.top(); stt.pop();
                char result;
                if(oper == '&') {
                    if(isFalse) {
                        result = 'f';
                    } else {
                        result = 't';
                    }
                } else if(oper == '|') {
                    if(isTrue) {
                        result = 't';
                    } else {
                        result = 'f';
                    }
                } else {
                    result = operand == 'f' ? 't' : 'f';
                }
                stt.push(result);
            } else {
                stt.push(itr);
            }
        }
        return stt.top() == 't' ? true : false;
    }
};

int main() {
    string expr = "&(|(f))";
    cout << Solution().parseBoolExpr(expr) << endl;
    return 0;
}