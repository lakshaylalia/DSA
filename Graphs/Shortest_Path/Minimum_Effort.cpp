#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m) return false;
        return true;
    }
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 0;
       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
       pq.push({0, {0,0}});
       while(!pq.empty()) {
        auto itr = pq.top();
        pq.pop();
        int diff = itr.first;
        int row = itr.second.first, col = itr.second.second;
        if(row == n-1 && col == m-1) return diff;
        for(int i = 0; i < 4; i++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if(isValid(nRow, nCol, n, m)) {
                int currDiff = abs(heights[nRow][nCol] - heights[row][col]);
                if(max(currDiff, diff) < dis[nRow][nCol]) {
                    dis[nRow][nCol] = max(currDiff, diff);
                    pq.push({max(currDiff, diff), {nRow, nCol}});
                }
            }
        }
       }
       return -1;
    }
};

int main() {
    vector<vector<int>> heights = {{1,2,3},{3,8,2},{5,3,5}};
    cout << Solution().minimumEffortPath(heights) << endl;
    return 0;
}