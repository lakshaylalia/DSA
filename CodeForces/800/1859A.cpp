#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> arr) {
    vector<int> b, c;
    int maxi = *max_element(arr.begin(), arr.end());
    for(auto itr : arr) {
        if(itr != maxi) {
            b.push_back(itr);
        } else {
            c.push_back(itr);
        }
    } 
    if(b.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << b.size() << " " << c.size() << endl;
        for(auto itr : b) {
            cout << itr << " ";
        }
        cout << endl;
        for(auto itr : c) {
            cout << itr << " ";
        }
        cout << endl;
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