#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &arr) {
    if(arr[0] != 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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