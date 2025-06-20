#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval) {
        vector<vector<int>> updatedInterval;
        bool inserted = false;

        for(auto itr : Intervals) {
            if(itr[1] < newInterval[0]) { // for intervals that are before the new interval
                updatedInterval.push_back(itr);
            }
            else if(itr[0] <= newInterval[1]) { // for intervals that overlap with the new interval  
                newInterval[0] = min(newInterval[0], itr[0]);
                newInterval[1] = max(newInterval[1], itr[1]);
            }
            else { // for intervals that are after the new interval
                if (!inserted) {
                    updatedInterval.push_back(newInterval);
                    inserted = true;
                }
                updatedInterval.push_back(itr);
            }
        }
        if (!inserted) {
            updatedInterval.push_back(newInterval);
        }
        return updatedInterval;
    }
};


int main() {
    vector<vector<int>> interval = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {1, 8};
    // vector<vector<int>> interval = {{1, 2}, {3, 5}, {6, 7}, {8, 10}};
    // vector<int> newInterval = {4, 8};
    vector<vector<int>> result = Solution().insertNewInterval(interval, newInterval);
    for(auto itr : result) {
        for(auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}