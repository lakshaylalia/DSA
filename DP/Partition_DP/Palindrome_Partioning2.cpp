#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(int i, int j, const string &s) {
        while(i <= j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
    int Recurssive(int i, string &s) {
        if(i == s.size()) {
            return 0;
        }
        int cuts = INT_MAX;
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                cuts = min(cuts, 1 + Recurssive(j+1, s));
            }
        }
        return cuts;
    }

    int Memoization(int i, string &s, vector<int> &dp) {
        if(i == s.size()) {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int cuts = INT_MAX;
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                cuts = min(cuts, 1+ Memoization(j+1, s, dp));
            }
        }
        return dp[i] = cuts;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int cuts = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalindrome(i, j, s)) {
                    cuts = min(cuts, 1+ dp[j+1]);
                }
            }
            dp[i] = cuts;
        }
        return dp[0]-1;
    }
};

int main() {
    string s = "aab";
    cout << Solution().minCut(s) << endl;
    return 0;
}