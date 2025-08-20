#include <bits/stdc++.h>
using namespace std;

class Solution {  
private:
    bool Recurssive(int i, int j, string &s, string &p) {
        if(i < 0) {
            if(j < 0) {
                return true;
            } else {
                for(int k = j; k >= 0; k--) {
                    if(p[k] != '*') {
                        return false;
                    }
                }
                return true;
            }
        }
        if(j < 0) {
            return false;
        }
        if(s[i] == p[j] || p[j] == '?') {
            return Recurssive(i - 1, j - 1, s, p);
        }
        else if(p[j] == '*') {
            return Recurssive(i, j - 1, s, p) || Recurssive(i - 1, j, s, p);
        }
        return false;
    }

    bool Memoization(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if(i < 0) {
            if(j < 0) {
                return 1;
            } else {
                for(int k = j; k >= 0; k--) {
                    if(p[k] != '*') {
                        return 0;
                    }
                }
                return 1;
            }
        }
        if(j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = Memoization(i - 1, j - 1, s, p, dp);
        } else if(p[j] == '*') {
            return dp[i][j] = Memoization(i, j - 1, s, p, dp) || Memoization(i - 1, j, s, p, dp);
        }
        return dp[i][j] = 0;
    }

    bool Tabulation(string &s, string &p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for(int j = 1; j <= m; j++) {
            bool flag = true;
            for(int k = 0; k < j; k++) {
                if(p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }

public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        prev[0] = 1;
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            fill(curr.begin(), curr.end(), 0);
            curr[0] = 0;

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    string s = "aa";
    string p = "*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}