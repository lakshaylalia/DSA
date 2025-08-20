#include <bits/stdc++.h>
using namespace std;

void solve(uint64_t &n, uint64_t &k) {
    if(n&1) {
        if(k&1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        uint64_t n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}