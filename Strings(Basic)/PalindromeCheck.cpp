#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool palindromeCheck(string& s) {
        int n = s.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            if (s[low] != s[high]) {
                return false;
            }
            low++, high--;
        }
        return true;
    }
};

int main() {
    string s = "abba";
    cout << Solution().palindromeCheck(s) << endl;
    return 0;
}