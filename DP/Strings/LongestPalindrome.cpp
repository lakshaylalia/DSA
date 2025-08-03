#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Recurssive(int i, int j, string &s) {
        if(i == j) {
            return 1;
        }
        if( i > j) {
            return 0;
        }

        if(s[i] == s[j]) {
            return 2+Recurssive(i+1, j-1, s);
        }
        return max(Recurssive(i+1, j, s), Recurssive(i, j-1, s));
    }

    int Memoization(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i == j) {
            return 1;
        }
        if(i > j) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == s[j]) {
            return dp[i][j] = 2+Memoization(i+1, j-1, s, dp);
        }
        return dp[i][j] = max(Memoization(i+1, j, s, dp), Memoization(i, j-1, s, dp));
    }
    
public:
    int longestPalindromeSubseq(string s) {
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
        return prev[m];
    }
};

int main() {
    int t;
     cin >> t;
     while(t--) {
        string s;
        cin >> s;
        cout << Solution().longestPalindromeSubseq(s) << endl;
     }
    return 0;
}