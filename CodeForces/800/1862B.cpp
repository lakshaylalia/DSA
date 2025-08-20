#include <bits/stdc++.h>
using namespace std;

void  solve(int n, vector<int> arr) {
    if(n == 1) {
        cout << 1 << endl;
        cout << arr[0] << endl;
        return;
    }
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 1; i < n; i++) {
        if(arr[i] >= arr[i-1]) {
            ans.push_back(arr[i]);
        } else {
            ans.push_back(arr[i]);
            ans.push_back(arr[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto itr : ans) {
        cout << itr << " ";
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