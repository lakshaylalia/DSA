#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxLen = 0;
//         int maxFreq = 0;
//         int l = 0, r = 0; 
//         int hash[26] = {0};
//         while (r < s.size()) {
//             hash[s[r] - 'A']++;
//             maxFreq = max(maxFreq, hash[s[r] - 'A']); 
//             while ((r - l + 1) - maxFreq > k) {
//                 maxFreq = 0;
//                 for (int i = 0; i < 26; ++i) {
//                     maxFreq = max(maxFreq, hash[i]);
//                 }
                
//                 l++; 
                
                
//             }
//             maxLen = max(maxLen, r - l + 1);
//             r++;
//         }
//         return maxLen;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int hash[26] = {0};
        int left = 0, right = 0;
        int maxLen = 0;
        int maxFreq = 0;
        while(right < n) {
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);
            if(right - left + 1 - maxFreq > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};


int main() {
    string s = "ABAB";
    cout << Solution().characterReplacement(s, 2) << endl;
    return 0;
}