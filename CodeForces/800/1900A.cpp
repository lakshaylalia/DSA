#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int &n) {
    if(n == 1) {
        if (s[0] == '.') {
            return 1;
        } else {
            return 0;
        }
    }
    uint64_t emptyCells = 0;
    for(int i = 1; i < n-1; i++) {
        if(s[i] != '#') {
            if(s[i-1] == '.' && s[i+1] == '.') {
                return 2;
            }
            emptyCells++;
        }
    }

    if(s[0] == '.') {
        emptyCells++;
    }
    if(s[n-1] == '.') {
        emptyCells++;
    }
    return emptyCells;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        cout << solve(s, n) << endl;
    }
    return 0;
}