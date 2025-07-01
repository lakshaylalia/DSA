#include <bits/stdc++.h>
using namespace std;

//1. Try to represent the problem in term of index
//2. Do all possible stuffs on thta index according to the problem statement
//3. If question says all ways sum up all stuffs
// If question says minimum find mimimum of all the stuffs
// If question says maximum find maximum of all the stuffs



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursion
    int countWaysRec(int n) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        return countWaysRec(n - 1) + countWaysRec(n - 2);
    }

    // Recursion + Memoization
    int countWaysMemo(int n, vector<int> &dp) {
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = countWaysMemo(n - 1, dp) + countWaysMemo(n - 2, dp);
    }

    // Tabulation
    int countWaysTabu(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] += dp[i - 1];
            if (i - 2 >= 0) dp[i] += dp[i - 2];
        }
        return dp[n];
    }

    // Space Optimization
    int countWaysSpace(int n) {
        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1] (when i=1)
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

public:
    int climbStairs(int n) {
        // return countWaysRec(n);              // Plain Recursion
        // vector<int> dp(n + 1, -1);           // For Memoization
        // return countWaysMemo(n, dp);         // Memoization
        // return countWaysTabu(n);             // Tabulation
        return countWaysSpace(n);               // Space Optimization
    }
};


int main() {
    int n = 2;
    cout << Solution().climbStairs(n) << endl;
    return 0;
}