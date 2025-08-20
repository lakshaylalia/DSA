#include <bits/stdc++.h>
using namespace std;

void solve(int &n, vector<int> &arr) {
    for(int i = 0; i < n; i++) {
        cout << n+1-arr[i] << " ";
    }
    cout << endl;
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