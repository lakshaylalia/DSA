#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c) {
    if(c & 1) {
        if(a >= b) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    } else {
        if(a > b) {
            cout << "First\n";
        } else {
            cout << "Second\n";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    return 0;
}