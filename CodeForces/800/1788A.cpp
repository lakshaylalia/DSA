#include <bits/stdc++.h>
using namespace std;

int64_t solve(int &n, vector<int> &arr) {
    int64_t x = 0;
    for(auto itr : arr) {
        if(itr == 2) {
            x++;
        }
    }
    if(x&1) {
        return -1;
    }
    int64_t cnt = 0; 
    for(int i =  0; i < n; i++) {
        if(arr[i] == 2) {
            cnt++;
        }
        if(cnt == x/2) {
            return i+1;
        }
    }
    return -1;
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