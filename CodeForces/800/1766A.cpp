#include <bits/stdc++.h>
using namespace std;

int solve(uint64_t &n) {
    if(n <= 10) {
        return n;
    } else if(n <= 100) {
        return (10 + (n-10)/10);
    } else if(n <= 1000) {
        return (19 + (n-100)/100);
    } else if(n <= 10000) {
        return (28 + (n-1000)/1000);
    } else if(n <= 100000) {
        return (37 + (n-10000)/10000);
    } 
    return (46 + (n-100000)/100000);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        uint64_t n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}