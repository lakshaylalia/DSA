#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> inc(n, 1), dec(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] && inc[i] < inc[prev] + 1) {
                    inc[i] = inc[prev] + 1;
                }
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int next = n-1; next > i; next--) {
                if(arr[next] < arr[i] && dec[i] < dec[next] + 1) {
                    dec[i] = dec[next] + 1;
                }
            }
            maxi = max(maxi, inc[i] + dec[i] - 1);
        }
        return maxi;
    }
};


int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 40, 30, 20};
    cout << Solution().LongestBitonicSequence(arr) << endl;
    return 0;
}