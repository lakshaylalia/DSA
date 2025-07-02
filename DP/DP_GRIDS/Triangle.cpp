#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void minimumTotalRecursive(int idx, int curr_sum, int &leastSum, vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(idx >= n) {
            leastSum = min(leastSum, curr_sum);
            return;
        }

        for(int i = 0; i <= idx; i++) {
            minimumTotalRecursive(idx + 1, curr_sum + triangle[idx][i], leastSum, triangle);
        }
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int leastSum = INT_MAX;
        minimumTotalRecursive(0, 0, leastSum, triangle);
        return leastSum;
    }
};

int main() {
    // vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle = {{-1}, {2, 3}, {1, -1, -3}};
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}