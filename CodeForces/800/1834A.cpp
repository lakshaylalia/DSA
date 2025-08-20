#include <bits/stdc++.h>
using namespace std;

int solve(int &n, vector<int> &arr) {
    int oper = 0;
    int pos = 0, neg = 0;
    for(auto itr : arr) {
        if(itr == -1) {
            neg++;
        } else {
            pos++;
        }
    }
    if(pos == neg) {
        if(neg & 1) {
            return 1;
        } else {
            return 0;
        }
    } else if(pos > neg) {
        if(neg & 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int diff = neg - pos;
        oper = (diff+1)/2;
        neg = neg - oper;
        if(neg & 1) {
            oper++;   
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