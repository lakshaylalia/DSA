#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool comparator(const string &a, const string &b) {
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n == 1) {
            return 1;
        }
        sort(words.begin(), words.end(), comparator);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(words[i].size() - words[prev].size() == 1) {
                    int j = 0, k = 0;
                    int diff = 0;
                    while(j < words[prev].size()) {
                        if( k < words[i].size() && words[prev][j] != words[i][k]) {
                            k++;
                            diff++;
                            if(diff > 1) {
                                break;
                            }
                        } else {
                            k++;
                            j++;
                        }
                    }
                    if(diff > 1) {
                        continue;
                    } else {
                        dp[i] = max(dp[i], dp[prev] + 1);
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

int main() {
    vector<string> words = {"abcd","dbqca"};
    cout << Solution().longestStrChain(words) << endl;
    return 0;
}