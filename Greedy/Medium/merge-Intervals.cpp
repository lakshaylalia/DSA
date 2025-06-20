#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], b = intervals[0][1];
        vector<vector<int>> newIntervals;
        for(int i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if(start <= b && end >= a) {
                a = min(a, start);
                b = max(b, end);
            } else {
                newIntervals.push_back({a, b});
                a = start, b = end;

            }
        }
        newIntervals.push_back({a, b});
        return newIntervals;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,4},{0,0}};
    vector<vector<int>> ans = Solution().merge(intervals);
    for(auto itr : ans) {
        cout << itr[0] << " " << itr[1] << endl;
    }
    return 0;
}