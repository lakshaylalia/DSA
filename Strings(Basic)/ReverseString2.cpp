#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int low = 0, high = n - 1;
        while(low <= high) {
          swap(s[low], s[high]);
          low++, high--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution().reverseString(s);
    return 0;
}