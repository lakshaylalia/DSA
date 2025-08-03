#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        string txt2 = s, txt1 = s;
        reverse(txt2.begin(), txt2.end());
        int n = txt1.size(), m = txt2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (txt1[i - 1] == txt2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        int longest = prev[m];
        return s.length() - longest;
    }
};

int main() {
    string s = "zzazz";
    cout << Solution().minInsertions(s) << endl;
    return 0;
}