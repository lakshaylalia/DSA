#include <bits/stdc++.h>
using namespace std;

// class Solution{
// private:
//     vector<int> clacZValue(string s) {
//         int n = s.size();
//         vector<int> Z(n, 0);
//         for(int i = 1; i < n; i++) {
//             while(i + Z[i - 1] < n && s[i + Z[i]] == s[Z[i]]) {
//                 Z[i]++;
//             }
//         }
//         return Z;
//     }
// public:
//     vector<int> search(string text , string pattern){
//         int n = text.size();
//         return clacZValue(text);

//      }
// };


class Solution {
private:
    vector<int> calcZValue(string s) {
        int n = s.size();
        vector<int> Z(n, 0);
        int left = 0, right = 0;

        for(int i = 1; i < n; i++) {
            if(i > right) {
               while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) {
                Z[i]++;
               }
            } else {
                if(i + Z[i-left] <= right) {
                    Z[i] = Z[i-left];
                } else {
                    Z[i] = right-i+1;
                    while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]]) {
                        Z[i]++;
                    }
                }
            }
            left = i, right = i + Z[i] - 1;
        }
        return Z;
    }

public:
    vector<int> search(string text, string pattern) {
        string s = pattern + '$' + text;
        vector<int> Z = calcZValue(s);
        vector<int> ans;
        int m = pattern.size();

        for (int i = m + 1; i < s.size(); i++) {
            if (Z[i] == m) {
                ans.push_back(i - m - 1);
            }
        }
        return ans;
    }
};




int main() {
    string text = "abacaba";
    vector<int> ans = Solution().search(text, "aba");
    for(auto itr : ans) {
        cout << itr << " ";
    }
    return 0;
}