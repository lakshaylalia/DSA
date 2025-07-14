#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1e9+7;

    int countPartitionsSpaceOptimized(int idx, int target, vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(target+1, 0);
        prev[0] = 1;
        if(arr[0] <= target) {
            prev[arr[0]] = 1;
        }
        for(int idx = 1; idx < n; idx++) {
            vector<int> curr(target+1, 0);
            curr[0] = 1;
            for(int k = 1; k <= target; k++) {
                int skip = prev[k];
                int take = 0;
                if(arr[idx] <= k) {
                    take = prev[k-arr[idx]];
                }
                curr[k] = (take + skip)%mod;
            }
            prev = curr;
        }
        return prev[target];
    }

public:
   int countPartitions(int n, int diff, vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int target = (totalSum+diff);
        if(target & 1) {
            return 0;
        }
        target = target / 2;
        return countPartitionsSpaceOptimized(0, target, arr);
    }
};


int main() {
    vector<int> arr = {1, 1, 2, 3};
    cout << Solution().countPartitions(4, 1, arr);
    return 0;
}