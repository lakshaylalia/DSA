#include <bits/stdc++.h>
using namespace std;

bool comparator( vector<int> &a,  vector<int> &b) { 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a[0] < b[0];
}


int main() {
    vector<vector<int>> v = {{1, 2, 3}, {15, 10, 6}, {17, 78, 9}};
    sort(v.begin(), v.end(), comparator);
    for(auto itr : v) {
        for(auto ptr : itr) {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}