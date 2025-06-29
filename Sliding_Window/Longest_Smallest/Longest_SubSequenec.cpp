#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int n = s.size();
        int HashLen = 256; 
        int hash[HashLen]; 

        for (int i = 0; i < HashLen; ++i) {
            hash[i] = -1;
        }

        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         unordered_set<char> stt;
//         int left = 0, right = 0;
//         int len = 0, maxLen = 0;
//         while(right < n) {
//             if(stt.find(s[right]) == stt.end()) {
//                 stt.insert(s[right]);
//                 len++;
//                 right++;
//             } else {
//                 stt.erase(s[left]);
//                 left++;
//                 len--;
//             }
//             maxLen = max(len, maxLen);
//         }
//         return maxLen;
//     }
// };

int main() {
    string s = "aaaa";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}