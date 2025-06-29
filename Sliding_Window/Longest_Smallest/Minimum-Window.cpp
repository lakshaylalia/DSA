#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) return "";

        int need[256] = {0};
        for (char ch : t) {
            need[ch]++;
        }

        int left = 0, start = 0, minLen = INT_MAX;
        int count = 0;

        for (int right = 0; right < n; right++) {
            if (need[s[right]] > 0) {
                count++;
            }
            need[s[right]]--;
            while (count == m) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                need[s[left]]++;
                if (need[s[left]] > 0) {
                    count--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = Solution().minWindow(s, t);
    cout  << result << endl;

    return 0;
}