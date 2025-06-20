#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        int total = 0;
        for(auto itr : candies) {
            total += itr;
        }
        return total;
    }
};

int main() {
    vector<int> ratings = {1, 2, 2};
    cout << Solution().candy(ratings) << endl;
    return 0;
}