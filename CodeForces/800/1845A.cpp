#include <bits/stdc++.h>
using namespace std;

bool Recursive(int i, int n, int k, int x, vector<int> &ans) {
    if (n < 0 || i > k) {
        return false;
    }

    if (n == 0) {
        return true;
    }

   if( Recursive(i + 1, n, k, x, ans)) {
    return true;
   }

    if (i != x) {
        ans.push_back(i);
        if(Recursive(i, n - i, k, x, ans)) {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

void solve(int n, int k, int x) {
    vector<int> ans;
    if (Recursive(1, n, k, x, ans)) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int num : ans) {
            cout << num << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        solve(n, k, x);
    }
    return 0;
}