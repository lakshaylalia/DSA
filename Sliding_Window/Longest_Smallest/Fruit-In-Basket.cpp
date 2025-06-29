#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        unordered_map<int, int> mpp;
        int n = fruits.size();
        int left = 0, right = 0;
        int maxLen = 0;
        while(right < n) {
          mpp[fruits[right]]++;
          if(mpp.size() > 2) {
            mpp[fruits[left]]--;
            if(mpp[fruits[left]] == 0) {
              mpp.erase(fruits[left]);
            }
            left++;
          }
          if(mpp.size() <= 2) {
            maxLen = max(maxLen, right-left+1);
          }
          right++;
        }
        return maxLen;
    }
};

int main() {
    vector<int> fruits = {1, 2, 1};
    cout << Solution().totalFruits(fruits) << endl;
    return 0;
}