#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], b = intervals[0][1];
        vector<vector<int>> updatedInterval;
        bool intervalInserted = false;
        if(newInterval[0] <= b) {
            a = min(a, newInterval[0]);
            b = max(b, newInterval[1]);
            intervalInserted = true;
        }
        for(auto itr : intervals) {
            int start = itr[0], end = itr[1];
            if(start <= b) {
                a = min(a, start);
                b = max(b, end);
            } else {
                updatedInterval.push_back({a, b});
                a = start, b = end;
                if(!intervalInserted) {
                    if(newInterval[0] <= b) {
                        a = min(a, newInterval[0]);
                        b = max(b, newInterval[1]);
                        intervalInserted = true;
                    }
                }          
            }
        }
        updatedInterval.push_back({a, b});
        if(!intervalInserted) {
            updatedInterval.push_back({newInterval[0], newInterval[1]});
        }
        return updatedInterval;
    }
};


int main() {
    vector<vector<int>> intervals = { {1, 2},{3, 5}, {6, 7}, {8, 10},{12, 16}};
    vector<int> newInterval = {4, 10};
    vector<vector<int>> ans = Solution().insert(intervals, newInterval);
    for (auto itr : ans) {
        cout << itr[0] << " " << itr[1] << endl;
    }
    return 0;
}