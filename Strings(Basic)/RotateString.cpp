#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }
        int n = s.size();
        string x = s;
        x += x;
        return x.find(goal) != string::npos;
    }
};

int main() {
    string s = "abcde";
    string goal = "cdeab";
    cout << Solution().rotateString(s, goal) << endl;
    return 0;
}