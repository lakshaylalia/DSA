#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for (int i = n - 1; i >= 0; i--) {
            int digit = num[i] - '0';
            if (digit & 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};


int main() {
    string num = "52";
    cout << Solution().largestOddNumber(num) << endl;
    return 0;
}