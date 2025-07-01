#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int calcEnergyRec(int idx, int k, vector<int>& heights) {
        if(idx <= 0) {
            return 0;
        }
        int energy = INT_MAX;
        for(int i = idx-k; i <= idx-1; i++) {
            int currEnergy = abs(heights[idx] - heights[i]) + calcEnergyRec(i, k, heights);
            energy = min(energy, currEnergy);
        }
        return energy;
    }

    int calcEnergyMem(int idx, int k, vector<int>& heights, vector<int>& dp) {
        if(dp[idx] != -1) {
            return dp[idx];
        }
        if(idx <= 0) {
            return 0;
        }
        dp[idx] = INT_MAX;
        for(int i = idx-k; i <= idx-1; i++) {
            int currEnergy = INT_MAX;
            if(i >= 0) {
                currEnergy = abs(heights[idx] - heights[i]) + calcEnergyMem(i, k, heights, dp);
            }
            dp[idx] = min(dp[idx], currEnergy);
        }
        return dp[idx];
    }

    int calcEnergyTabOpt(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(k, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int minCost = INT_MAX;
        for(int jump = 1; jump <= k; jump++) {
            if(i - jump >= 0) {
                int cost = dp[(i - jump) % k] + abs(heights[i] - heights[i - jump]);
                minCost = min(minCost, cost);
            }
        }
        dp[i % k] = minCost;
    }
    return dp[(n - 1) % k];
}




public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        // return calcEnergyRec(n-1, k, heights);
        // return calcEnergyMem(n-1, k, heights, dp);
        // return calcEnergyTab(heights, k);
        return calcEnergyTabOpt(heights, k);

    }
};


int main() {
    vector<int> heights = {15, 4, 1, 14, 15};
    int k = 3;
    cout << Solution().frogJump(heights, k) << endl;
    return 0;
}