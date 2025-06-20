#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int count = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                count++;
                i++, j++;
            } else if(g[i] > s[i]) j++;
        }
        return count;
    }
};

int main() {
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    cout << Solution().findContentChildren(g, s) << endl;
    return 0;
}