#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &arr) {
    uint64_t sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum & 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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
        solve(n, arr);
    }
    return 0;
}