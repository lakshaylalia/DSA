#include <bits/stdc++.h>
using namespace std;

int solve(int &n, string &s) {
    int i = 0, j = n - 1;
    while(i < j) {
        if(s[i] == '1' && s[j] == '0') {
            i++;
            j--;
        } else if(s[i] == '0' && s[j] == '1') {
            i++;
            j--;
        } else {
            return (j-i+1);
        }
    }
    return i == j ? 1 : 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s(n, ' ');
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        cout << solve(n, s) << endl;
    }
    return 0;
}