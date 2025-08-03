#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Recurssion(int i, int j, string &s, string &t) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }

        if(s[i] == t[j]) {
            return Recurssion(i-1, j-1, s, t) + Recurssion(i-1, j, s, t);
        }
        return Recurssion(i-1, j, s, t);
    }

    int Memoization(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }

        if(s[i] == t[j]) {
            return dp[i][j] =  Recurssion(i-1, j-1, s, t) + Recurssion(i-1, j, s, t);
        }
        return dp[i][j] = Recurssion(i-1, j, s, t);
    }

    int Tabulation(string &s, string &t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }

    int TabulationSpaceOptimized(string &s, string &t) {
        int n = s.size(), m = t.size();
        vector<long long> prev(m+1, 0);
        prev[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j >= 1; j--) {
                if(s[i-1] == t[j-1]) {
                    prev[j] = prev[j-1] + prev[j];
                }
            }
        }
        return prev[m];
    }

public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // return Recurssion(n-1, m-1, s, t);
        // vector<vector<long long>> dp(n, vector<long long>(m, -1));
        // return Memoization(n-1, m-1, s, t, dp);
        // return Tabulation(s, t);
        return TabulationSpaceOptimized(s, t);
    }
};

int main() {
    string s = "aaa", t = "aa";
    cout << Solution().numDistinct(s, t);
    return 0;
}
