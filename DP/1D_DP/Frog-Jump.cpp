#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    //  Plain Recursion
    int calcEnergyRec(int idx, vector<int>& heights) {
        if(idx == 0) return 0;
        int left = calcEnergyRec(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1) {
            right = calcEnergyRec(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
        }
        return min(left, right);
    }

    //  Recursion + Memoization
    int calcEnergyMemo(int idx, vector<int>& heights, vector<int>& dp) {
        if(idx == 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int left = calcEnergyMemo(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1) {
            right = calcEnergyMemo(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
        }
        return dp[idx] = min(left, right);
    }

    //  Tabulation
    int calcEnergyTabu(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for(int i = 1; i < n; i++) {
            int left = dp[i-1] + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1) {
                right = dp[i-2] + abs(heights[i] - heights[i-2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n-1];
    }

    //  Space Optimization
    int calcEnergySpace(vector<int>& heights) {
        int n = heights.size();
        int prev = 0;   // dp[i-1]
        int prev2 = 0;  // dp[i-2]

        for(int i = 1; i < n; i++) {
            int left = prev + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1) {
                right = prev2 + abs(heights[i] - heights[i-2]);
            }
            int curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        //  Recursion
        // return calcEnergyRec(n-1, heights);

        //  Recursion + Memoization
        // vector<int> dp(n, -1);
        // return calcEnergyMemo(n-1, heights, dp);

        //  Tabulation
        // return calcEnergyTabu(heights);

        //  Space Optimization
        return calcEnergySpace(heights);
    }
};


int main() {
    vector<int> heights = {2, 1, 3, 5, 4};
    cout << Solution().frogJump(heights) << endl;
    return 0;
}