#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        int maxFreq = 0;
        for (auto [_, f] : freq) maxFreq = max(maxFreq, f);

        vector<vector<char>> bucket(maxFreq + 1);
        for (auto [ch, f] : freq) {
            bucket[f].push_back(ch);
        }

        string ans = "";
        for (int i = maxFreq; i > 0; i--) {
            for (char ch : bucket[i]) {
                ans += string(i, ch); 
            }
        }

        return ans;
    }
};

int main() {
    string s = "tree";
    cout << Solution().frequencySort(s) << endl;
    return 0;
}