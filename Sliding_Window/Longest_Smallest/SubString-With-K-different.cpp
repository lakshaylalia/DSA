#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        unordered_map<char, int> mpp;
        int left = 0, right = 0;
        int maxLen = 0;
        while(right < n) {
            mpp[s[right]]++;
            if(mpp.size() > k) {
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }
            if(mpp.size() <= k) {
                maxLen = max(maxLen, right-left +1);
            }
            right++;
        }
        return maxLen;
    }
};

// class Solution {
// public:
//     int kDistinctChar(string& s, int k) {
//         int n = s.size();
//         unordered_map<char, int> mpp;
//         int left = 0, right = 0;
//         int maxLen = 0;
//         while(right < n) {
//           mpp[s[right]]++;
//           while(mpp.size() > k) {
//             mpp[s[left]]--;
//             if(mpp[s[left]] == 0) {
//               mpp.erase(s[left]);
//             }
//             left++;
//           }
//           if(mpp.size() <= k) {
//             maxLen = max(maxLen, right-left +1);
//           }
//           right++;
//         }
//         return maxLen;
//     }
// };

int main() {
    string s = "abccab";
    cout << Solution().kDistinctChar(s, 4) << endl;
    return 0;
}