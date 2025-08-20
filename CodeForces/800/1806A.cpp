#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t a, int64_t b, int64_t c, int64_t d) {
    if((a == c) && (b == d)) {
        return 0;
    }
    if(d < b) {
        return -1;
    }
    int64_t steps = d-b;
    int64_t x = a + steps;
    if(c - x > 0) {
        return -1;
    } else {
        steps += llabs(c - x);
    }
    return steps;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << endl;
    }
    return 0;
}