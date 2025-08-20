#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    if(n % 3 == 0) {
        cout << "Second\n";
        return;
    }
    cout << "First\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}