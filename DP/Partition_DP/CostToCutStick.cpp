#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int Recurssive(int i, int j, vector<int>& cuts) {
        if (i > j) {
            return 0;
        }
        int mini = INT_MAX;
        for (int len = i; len <= j; len++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       Recurssive(i, len - 1, cuts) +
                       Recurssive(len + 1, j, cuts);
            mini = min(mini, cost);
        }
        return mini;
    }
    int Memoization(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int len = i; len <= j; len++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       Memoization(i, len - 1, cuts, dp) +
                       Memoization(len + 1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) {
                    continue;
                }
                int mini = INT_MAX;

                for (int ind = i; ind <= j; ind++) {
                    int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] +
                              dp[ind + 1][j];

                    mini = min(mini, ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};



int main() {
    // vector<int> cuts = {1,3,4,5};
    vector<int> cuts = {5,6,1,4,2};
    cout << Solution().minCost(9, cuts) << endl;
    return 0;
}