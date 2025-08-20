#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, vector<int> &arr, vector<bool> &station) {
    int currFuel = 0, maxFuel = INT_MIN;    
    for(int i = 1; i <= x; i++) {
        currFuel--;
        if(station[i]) {
            maxFuel = max(maxFuel, abs(currFuel));
            currFuel = 0;
        }
    }
    for(int i = x-1; i >= 0; i--) {
        currFuel--;
        if(station[i]) {
            maxFuel = max(maxFuel, abs(currFuel));
            currFuel = 0;
        }
    }
    return maxFuel;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        vector<bool> station(x+1, false);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            station[arr[i]] = true;
        }
        cout << solve(n, x, arr, station) << endl;
    }
    return 0;
}