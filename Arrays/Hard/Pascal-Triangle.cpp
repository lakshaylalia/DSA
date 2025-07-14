#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    long long int fact(int n) {
        if(n == 0) {
            return 1;
        }
        return n * fact(n - 1);
    }
    long long nCr(int n, int r) {
        if(r > n-r) {
            r = n-r;
        }
        if(r == 0) {
            return 1;
        }
        return fact(n) / (fact(r) * fact(n - r)); 
    }

    vector<vector<int>> generateSimple(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++) {
            vector<int> curr;
            for(int j = 0; j <= i; j++) {
                curr.push_back(nCr(i, j));
            }
            ans.push_back(curr);
        }
        return ans;
    }

    vector<vector<int>> generateMemoization(int numRows) {
        vector<vector<int>> dp;
        for(int i = 0; i < numRows; i++) {
            vector<int> curr(i+1);
            dp.push_back(curr);
        }
        dp[0][0] = 1;
        for(int i = 1; i < numRows; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
        }
        return dp;
    }

    vector<int> generateBottomUp(int numRows) {
        vector<int> prev(1,1);
        for(int i = 1; i < numRows; i++) {
            vector<int> curr(i+1);
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    curr[j] = 1;
                } else {
                    curr[j] = prev[j-1] + prev[j];
                }
            }
            prev = curr;
        }
    }
public:
    vector<vector<int>> generate(int numRows) {
        return generateMemoization(numRows);
    }
};

int main() {
    int numRows = 6;
    vector<vector<int>> ans = Solution().generate(numRows);
    for(auto itr : ans) {
        for(auto ptr : itr) {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}