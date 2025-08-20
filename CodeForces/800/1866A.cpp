#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr) {
    int mini = INT_MAX;
    for(auto itr : arr) {
        int el = abs(itr);
        if(el == 0) {
            return 0;
        }
        mini = min(mini, el);
    }
    return mini;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solve(n, arr) << endl;
    return 0;
}