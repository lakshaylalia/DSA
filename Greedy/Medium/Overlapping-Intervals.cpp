#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    static bool comparator(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int lastInterval = intervals[0][1];
        int cnt = 0;
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= lastInterval) {
                lastInterval = intervals[i][1];
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 10}, {1, 4}, {3, 8}, {3, 4}, {4, 9}};
    cout << Solution().eraseOverlapIntervals(intervals) << endl;
    return 0;
}
