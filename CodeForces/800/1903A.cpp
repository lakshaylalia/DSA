#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int> &v) {
    bool flag = true;
    for(int i = 1; i < n; i++) {
        if(v[i-1] > v[i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        cout << "YES" << endl;
        return;
    }
    if(k == 0 || k == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve(n, k, v);
    }
    return 0;
}