#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int func(int idx1, int idx2, string s, string t, string txt1, string txt2, int &maxSize) {
        if(idx1 == s.size() && idx2 == t.size()) {
            if(s == t) {
                int n = s.length();
                maxSize = max(maxSize, n);
            } 
        }
        if(idx1 < txt1.length()) {
            s.push_back(txt1[idx1]);
            func(idx1 + 1, idx2, s, t, txt1, txt2, maxSize);
            s.pop_back();
        }
        if(idx2 < txt2.length()) {
            t.push_back(txt2[idx2]);
            func(idx1, idx2 + 1, s, t, txt1, txt2, maxSize);
            t.pop_back();
        }
        
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
    }
};

int main() {
    string text1 = "abcde", text2 = "ace";
    cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}