#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if (str.empty()) {
            return "";
        }
            
        sort(str.begin(), str.end()); 

        string first = str[0];
        string last = str[str.size() - 1];

        int minLength = min(first.size(), last.size());
        string ans = "";
        for (int i = 0; i < minLength; i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

int main() {
    vector<string> str = {"flower", "flow", "flight"};
    cout << Solution().longestCommonPrefix(str) << endl;
    return 0;
}