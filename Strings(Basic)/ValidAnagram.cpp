#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) {
//             return false;
//         }
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         int n = s.size();
//         for(int i = 0; i < n; i++) {
//             if(s[i] != t[i]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) {
            return false;
        }
        unordered_map<char, int> mpp;
        for(auto itr : s) {
            mpp[itr]++;
        }

        for(auto itr : t) {
            if(mpp.find(itr) != mpp.end()) {
                mpp[itr]--;
                if(mpp[itr] == 0) {
                    mpp.erase(itr);
                }
            }  else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";
    cout << Solution().isAnagram(s, t) << endl;
    return 0;
}