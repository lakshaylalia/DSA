#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &arr) {
    if(n == 2) {
        cout <<"Yes\n";
        return;
    }
    unordered_map<int, int> mpp;
    for(auto itr : arr) {
        mpp[itr]++;
        if(mpp.size() > 2) {
            cout <<"No\n";
            return;
        }
    }
    if(mpp.size() == 1) {
        cout <<"Yes\n";
        return;
    }
    int val1 = -1, val2 = -1;
    for(auto [key, val] : mpp) {
        if(val1 == -1) {
            val1 = val;
        } else {
            val2 = val;
        }
    }
    if(n % 2 == 0) {
        if(val1 == val2) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
    } else {
        if(val1+1 == val2 || val2+1 == val1) {
            cout <<"Yes\n";
        } else {
            cout <<"No\n";
        }
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