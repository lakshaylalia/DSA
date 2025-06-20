#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
   
   bool isValid(int row, int col, int n, int m){
    if(row < 0 || col < 0 || row >= n || col >= m) return false;
    return true;
   }
    
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    void bfs(vector<vector<int>> grid, vector<vector<int>> &vis, vector<vector<int>> &ans, queue<pair<pair<int,int>,int>> &q){
        int n = grid.size(), m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[row][col] = steps;
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(isValid(nRow, nCol, n, m) && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }
    }
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> ans (n,vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        bfs(grid, vis, ans, q);
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 1, 0, 1, 0},{0, 0, 1, 0, 1},{1, 1, 1, 0, 0}, {0, 0, 0, 1, 0}, {1, 0, 0, 0, 0}};
    vector<vector<int>> result = Solution().nearest(grid);
    for(const auto& row : result) {
        for(const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}