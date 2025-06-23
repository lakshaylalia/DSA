#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>stt;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (k > 0) {
                if (!stt.empty() && num[i] < stt.top()) {
                    stt.pop();
                    k--;
                }
            }
            stt.push(num[i]);
        }
        string ans;
        while (!stt.empty()) {
            ans.push_back(stt.top());
            stt.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s = "143229";
    cout << Solution().removeKdigits(s, 3) << endl;
    return 0;
}