#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkValidString(string s) {
        int n  = s.size();
        if(s[0] == ')' || s[n-1] == '(') {
            return false;
        }
        int min = 0, max = 0;
        for(auto itr : s) {
            if(itr == '(') {
                min++;
                max++;
            } else if(itr == ')') {
                min--;
                max--;
            } else {
                min--;
                max++;
            }
            if(min < 0) {
                min = 0;
            }
            if(max < 0) {
                return false;
            }
        }
        return min == 0;
    }
};

int main() {
    string s = "(*())";
    cout << Solution().checkValidString(s) << endl;
    return 0;
}