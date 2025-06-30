#include <bits/stdc++.h>
using namespace std;


// Converting recurssion to memoization involves
// 1. eclare a dp array of size n+1 with -1
// 2. check if the value is already present in dp array using (dp[n] != -1)
// 3. If not, compute the value and store it in the dp array before returning.
int fiboMemo(int n, vector<int> &dp) {
    if(n <= 1) {
        dp[n] = n;
        return n;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = fiboMemo(n - 1, dp) + fiboMemo(n - 2, dp);
}

// Converting memoization to tabulation involves
// 1. Declare a dp array of size n+1
// 2. Fill the base cases
// 3. Iterate from 2 to n and fill the dp array
// 4. Return the last element of the dp array
int fiboTabu(int n, vector<int> &dp) {
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Converting tabulation to space optimized involves
int fiboSpace(int n) {
    int prev1 = 1, prev2 = 0;
    for(int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << "Fibonacci using Memorization : " << fiboMemo(n, dp) << endl;
    cout << "Fibonnaci using Tabulation : " << fiboTabu(n, dp) << endl;
    cout << "Fibonnaci using tabulation space optimized : " << fiboSpace(n);
    return 0;
}