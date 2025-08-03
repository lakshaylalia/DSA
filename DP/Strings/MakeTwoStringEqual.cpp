// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string wordA1, string word2) {
        int n = wordA1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(wordA1[i-1] == word2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                } else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return n + m - 2*prev[m];
    }
};

int main() {
    return 0;
}