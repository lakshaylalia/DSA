#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> &arr) {
    int totalPoints = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr[i][j] == 'X') {
                if((i >= 4 && i <= 5) && (j >= 4 && j <= 5)) {
                    totalPoints += 5;
                } else if((i >= 3 && i <= 6) && (j >= 3 && j <= 6)) {
                    totalPoints += 4;
                } else if((i >= 2 && i <= 7) && (j >= 2 && j <= 7)) {
                    totalPoints += 3;
                } else if((i >= 1 && i <= 8) && (j >= 1 && j <= 8)) {
                    totalPoints += 2;
                } else {
                    totalPoints += 1;
                }
            }
        }
    }
    return totalPoints;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<vector<char>> arr;
        for(int i = 0; i < 10; i++) {
            vector<char> v(10);
            for(int j = 0; j < 10; j++) {
                cin >> v[j];
            }
            arr.push_back(v);
        }
        cout << solve(arr) << endl;
    }
    return 0;
}