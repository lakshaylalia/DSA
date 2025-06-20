#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m){
        if(row < 0 || col < 0 || row >= n || col >= m) return false;
        return true;
    }

    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>> &visited, queue<pair<int, int>> &q){
        int n = grid1.size(), m = grid1[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(isValid(nRow, nCol, n, m) && !visited[nRow][nCol] && grid2[nRow][nCol] == 1){
                    if(grid1[nRow][nCol] == grid2[nRow][nCol]){
                        q.push({nRow, nCol});
                        visited[nRow][nCol] = 1;
                    } else return false;
                }
            }
        }
        return true;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid1.size(), m = grid1[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid2[i][j] == 1 && !visited[i][j] && grid1[i][j] == grid2[i][j]){
                    q.push({i, j});
                    visited[i][j] = 1;
                    if(bfs(grid1, grid2, visited, q)) count++;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<int>> grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    vector<vector<int>> grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
    cout << Solution().countSubIslands(grid1, grid2) << endl;
    return 0;
}