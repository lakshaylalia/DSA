#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid){
    grid[i][j] = 0;
    for(int a = i - 1; a <= i + 1; a++){
        for(int b = j - 1; b <= j + 1; b++){
            if(a >= 0 && a < grid.size() && b >=0 && b < grid[0].size()){
                if(grid[a][b] == '1'){
                    dfs(a, b, grid);
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid){
    int islands = 0;
    for(int i = 0; i  < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                islands++;
                dfs(i, j, grid);
            }
        }
    }
    return islands;
}

int main() {
    vector<vector<char>> grid =  {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;
    return 0;
}