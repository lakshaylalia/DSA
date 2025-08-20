#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> arr) {
    int arrayXor = 0;
    for(auto itr : arr) {
        arrayXor ^= itr;
    }
    if(n&1) {
        return arrayXor;
    } else {
        return arrayXor == 0 ? 0 : -1;
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
        cout << solve(n, arr) << endl;
    }
    return 0;
}