#include <bits/stdc++.h>
using namespace std;

int solve(int &n, vector<int> &arr) {
    int i = 0, oper = 0;
    while(i < n-1) {
        int p1 = (arr[i] & 1);
        int p2 = (arr[i+1] & 1);
        if(p1 == p2) {
            i++;
            arr[i] = arr[i]*arr[i-1];
            oper++;
        } else {
            i++;
        }
    }
    return oper;
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