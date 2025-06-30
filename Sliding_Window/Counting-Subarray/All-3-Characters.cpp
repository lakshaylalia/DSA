#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;
//         for(int i = 0; i < n; i++) {
//             int hash[3] = {0};
//             for(int j = i; j < n; j++) {
//                 hash[s[j] - 'a']++;
//                 if(hash[0] && hash[1] && hash[2]) {
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size();
//         int cnt = 0;
//         for(int i = 0; i < n; i++) {
//             int hash[3] = {0};
//             for(int j = i; j < n; j++) {
//                 hash[s[j] - 'a']++;
//                 if(hash[0] && hash[1] && hash[2]) {
//                     cnt = (cnt + (n - j)) % 1000000007; // (n - j) is the number of substrings ending at index j
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        int lastSeen[3] = {-1, -1, -1};
        for(int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                cnt += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
            }
        }
        return cnt;
    }
};

int main() {
    string s;
    cin >> s;
    cout << Solution().numberOfSubstrings(s) << endl;
    return 0;
}