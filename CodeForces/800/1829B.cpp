#include <bits/stdc++.h>
using namespace std;

int  solve(int &n, vector<int> &arr) {
    int i = 0, j = 0;
    int maxi = INT_MIN;
    while(j < n) {
        if(arr[j] == 0) {
            maxi = max(maxi, j - i+1);
            j++;
        }  else {
            j++;
            i = j;
        }
    }
    return maxi == INT_MIN ? 0 : maxi;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(n, arr) << endl;
    }
    return 0;
}