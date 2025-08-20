#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            return 0;
        }
    }
    int mini = INT_MAX;
    for(int i = 1; i < n; i++) {
        if(arr[i]-arr[i-1] < mini) {
            mini = arr[i]-arr[i-1];
        }
    }
    return (mini + 1) / 2 + (mini + 1) % 2;
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