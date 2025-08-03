#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Recursive(int idx1, int idx2, string &txt1, string &txt2) {
        if(idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if(txt1[idx1] == txt2[idx2]) {
            return 1 + Recursive(idx1-1, idx2-1, txt1, txt2);
        }
        return max(Recursive(idx1-1, idx2, txt1, txt2), Recursive(idx1, idx2-1, txt1, txt2));
    }

    int Memoization(int idx1, int idx2, string &txt1, string &txt2, vector<vector<int>> &dp) {
        if(idx1 < 0 || idx2 < 0) {
            return 0;
        }
        if(dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if(txt1[idx1] == txt2[idx2]) {
            return dp[idx1][idx2] = 1 + Recursive(idx1-1, idx2-1, txt1, txt2);
        }
        return dp[idx1][idx2] = max(Recursive(idx1-1, idx2, txt1, txt2), Recursive(idx1, idx2-1, txt1, txt2));
    }

    int Tabulation(string &txt1, string &txt2) {
        int n = txt1.size(), m = txt2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(txt1[i-1] == txt2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int SpaceOptimization(string &txt1, string &txt2) {
        int n = txt1.size(), m = txt2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(txt1[i-1] == txt2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // return Recursive(n-1, m-1, text1, text2);
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Memoization(n-1, m-1, text1, text2, dp);
        // return Tabulation(text1, text2);
        return SpaceOptimization(text1, text2);
    }
};

int main() {
    string text1 = "abcde", text2 = "ace";
    cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
