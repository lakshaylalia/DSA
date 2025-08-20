#include <bits/stdc++.h>
using namespace std;

int computeGCD(int a, int b) {
    if(b == 0) {
        return a;
    }
    if(a == 0) {
        return b;
    }
    if(a == b) {
        return a;
    }
    if(a > b) {
        return computeGCD(a - b, b);
    }
    return computeGCD(a, b - a);
}

void solve(int &n, vector<int> &arr) {
    int found = false;
    for(int i = 0; i < n; i++) {
        int num1 = arr[i];
        for(int j = i + 1; j < n; j++) {
            if(gcd(num1, arr[j]) <= 2) {
                found = true;
                break;
            }
        }
        if(found) {
            break;
        }
    }
    if(found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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