#include <bits/stdc++.h>
using namespace std;

void solve(int &n, int &x) {
    vector<int> ans;
    int start = 0;
    int remaining = n;
    while(start != n) {
        if(remaining %  x != 0) {
            ans.push_back(remaining);
            break;
        } else {
            ans.push_back(remaining-start-1);
            start  = remaining - 1;
            remaining = n-start;
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
        int n, x;
        cin >> n >> x;
        solve(n, x);
    }
    return 0;
}