#include <bits/stdc++.h>
using namespace std;

// #define LC_HACK
// #ifdef LC_HACK
// const auto __ = []() {
//     struct ___ {
//         static void _() {
//             ofstream("display_runtime.txt") << 0 << '\n';
//         }
//     };
//     std::atexit(&___::_);
//     return 0;
// }();
// #endif

class Solution {
private:
    int Recurssive(int i, int j, string &word1, string &word2) {

        if(j < 0) {
            return i+1;
        }

        if(i < 0) {
            return j+1;
        }

        if(word1[i] != word2[j]) {
            int insert = 1 + Recurssive(i, j-1, word1, word2);
            int skip = 1 + Recurssive(i-1, j, word1, word2);
            int replace = 1 + Recurssive(i-1, j-1, word1, word2);
            return min(skip, min(replace, insert));
        }

        return Recurssive(i-1, j-1, word1, word2);
    }

    int Memoization(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {

        if(j < 0) {
            return i+1;
        }
        if(i < 0) {
            return j+1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(word1[i] != word2[j]) {
            int skip = 1 + Memoization(i, j-1, word1, word2, dp);
            int insert = 1 + Memoization(i-1, j, word1, word2, dp);
            int convert = 1 + Memoization(i-1, j-1, word1, word2, dp);
            return dp[i][j] = min(skip, min(insert, convert));
        }
        return dp[i][j] = Memoization(i-1, j-1, word1, word2, dp);
    }

    int Tabulation(string &word1, string &word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] != word2[j - 1]) {
                    int insert = 1 + dp[i][j - 1];
                    int remove = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min({insert, remove, replace});
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m + 1, 0);
        for(int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for(int i = 1; i <= n; i++) {
            vector<int> curr(m + 1, 0);
            curr[0] = i; 

            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] != word2[j - 1]) {
                    int insert = 1 + curr[j - 1];
                    int remove = 1 + prev[j];
                    int replace = 1 + prev[j - 1];
                    curr[j] = min({insert, remove, replace});
                } else {
                    curr[j] = prev[j - 1];
                }
            }
            prev = curr;
        }
        return prev[m];
    }

};

int main() {
    string word1 = "horse", word2 = "ros";
    cout << Solution().minDistance(word1, word2) << endl;
    return 0;
}