#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findNextIdx(int idx, vector<vector<int>> &events) {
        int n = events.size();
        int low = idx+1, high = n-1;
        int ans = n;
        int curr = events[idx][1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(events[mid][0] > curr) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int maxValueRecurssive(int idx, int k, vector<vector<int>> &events) {
        if(k == 0 || idx >= events.size()) {
            return 0;
        }
        int skip = maxValueRecurssive(idx + 1, k, events);

        int nextIdx = idx + 1;
        while(nextIdx < events.size() && events[nextIdx][0] <= events[idx][1]) {
            nextIdx++;
        }
        int take = events[idx][2] + maxValueRecurssive(nextIdx, k - 1, events);
        return max(take, skip);
    }

    int maxValueMemoization(int idx, int k, vector<vector<int>> &events, vector<vector<int>> &dp) {
        if(k == 0 || idx >= events.size()) {
            return 0;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        int skip = maxValueMemoization(idx + 1, k, events, dp);
        
        int n = events.size();
        // int nextIdx = idx + 1;
        // while(nextIdx < n && events[nextIdx][0] <= events[idx][1]) {
        //     nextIdx++;
        // }
        int nextIdx = findNextIdx(idx, events);
        int take = events[idx][2] + maxValueMemoization(nextIdx, k - 1, events, dp);
        return dp[idx][k] = max(take, skip); 
    }

    int maxValueTabulation(vector<vector<int>> &events, int k) {
        int n =  events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= k; j++) {
                int skip = dp[i+1][j];
                int take = events[i][2];
                int nextIdx = findNextIdx(i, events);
                take += dp[nextIdx][j-1];
                dp[i][j] = max(take, skip);
            }
        }
        return dp[0][k];
    }

    // int maxValueTabulationSpaceOptimized(vector<vector<int>> &events, int k) {
    //     int n = events.size();
    //     vector<int> prev(k+1, 0);
    //     for(int i = n-1; i >= 0; i--) {
    //         vector<int> curr(k+1, 0);
    //         for(int j = 1; j <= k; j++) {
    //             int skip = prev[j];
    //             int take = events[i][2];
    //             int nextIdx = findNextIdx(i, events);
    //             if(nextIdx < n) {
    //                 take += prev[j-1];
    //             }
    //             curr[j] = max(take, skip);
    //         }
    //         prev = curr;
    //     }
    //     return prev[k];
    // }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // return maxValueRecurssive(0, k, events);
        // return maxValueMemoization(0, k, events, dp);
        return maxValueTabulation(events, k);
    }
};

int main() {
    // vector<vector<int>> events = {{1,2,4},{3,4,3},{2,3,1}};
    vector<vector<int>> events = {{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
    cout << Solution().maxValue(events, 3) << endl;
    return 0;
}