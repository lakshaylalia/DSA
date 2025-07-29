#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0, down = n-1;
        
        while(top < down) {
            if(M[top][down] == 1) {
                top = top + 1;
            }
            else if(M[down][top] == 1) {
                down = down - 1;
            }
            else {
                top++;
                down--;
            }
        }

        if(top > down) return -1;
        
        for(int i=0; i < n; i++) {
            if(i == top) continue;
            if(M[top][i] == 1 || M[i][top] == 0) {
                return -1;
            }
        }

        return top;
    }
};

// class Solution {
// public:
//     int celebrity(vector<vector<int>> &M){
//         int n = M.size();
//         vector<int> knowMe(n, 0);
//         vector<int> Iknow(n, 0);
        
//         for(int i=0; i < n; i++) {
//             for(int j=0; j < n; j++) {
//                 if(M[i][j] == 1) {
//                     knowMe[j]++;
//                     Iknow[i]++;
//                 }
//             }
//         }
        
//         for(int i=0; i < n; i++) {
//             if(knowMe[i] == n-1 && Iknow[i] == 0) {
//                 return i;  
//             }
//         }     
//         return -1;
//     }
// };

int main() {
    vector<vector<int> > M = {{0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
    cout << Solution().celebrity(M) << endl;
    return 0;
}