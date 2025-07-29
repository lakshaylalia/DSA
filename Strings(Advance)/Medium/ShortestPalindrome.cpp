#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);
        int i = 1, j = 0;

        while (i < n) {
            if (s[i] == s[j]) {
                LPS[i] = j + 1;
                i++, j++;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = LPS[j - 1];
                }
                if (s[i] == s[j]) {
                    LPS[i] = j + 1;
                    j++;
                }
                i++;
            }
        }

        return LPS;
    }

public:
    string shortestPalindrome(string s) {
        if (s == "") {
            return s;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        string res = s + '$' + rev;
        vector<int> LPS = computeLPS(res);
        int m = res.size();
        int n = s.size();
        if (LPS[m - 1] == n) {
            return s;
        }
        int diff = n - LPS[m - 1];
        string sub = rev.substr(0, diff);
        s = sub + s;
        return s;
    }
};

int main() {
    string s = "aacecaaa";
    cout << Solution().shortestPalindrome(s) << endl;
    return 0;
}