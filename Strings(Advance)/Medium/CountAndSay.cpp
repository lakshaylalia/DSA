#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<char>> helper(const string& num) {
        vector<vector<char>> freq;
        int cnt = 1;

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == num[i - 1]) {
                cnt++;
            } else {
                string s = to_string(cnt);
                vector<char> temp(s.begin(), s.end());
                temp.push_back(num[i - 1]);
                freq.push_back(temp);
                cnt = 1;
            }
        }

        string s = to_string(cnt);
        vector<char> temp(s.begin(), s.end());
        temp.push_back(num.back());
        freq.push_back(temp);
        return freq;
    }

    string findRLE(const string& num) {
        vector<vector<char>> freq = helper(num);
        string ans = "";
        for (auto& itr : freq) {
            for (char ch : itr) {
                ans += ch;
            }
        }
        return ans;
    }

public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string prev = countAndSay(n - 1);
        return findRLE(prev);
    }
};


int main() {
    cout << Solution().countAndSay(4) << endl;
    return 0;
}