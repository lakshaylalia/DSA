#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int> &arr) {
    for(auto itr : arr) {
        if(itr == k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n , k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, k, arr);
    }
    return 0;
}