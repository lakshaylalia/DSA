#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int row, int col, int newCol){
    if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()) return;
    if(image[row][col] == newCol || image[row][col] == 0) return;
    image[row][col] = newCol;
    if(row >= 0 && row < image.size() && col >= 0 && col < image[0].size()){
        dfs(image, row - 1, col, newCol);
        dfs(image, row + 1, col, newCol);
        dfs(image, row, col - 1, newCol);
        dfs(image, row, col + 1, newCol);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc, int newColor){
    if(image[sr][sc] != newColor && image[sr][sc] != 0){
        dfs(image, sr, sc, newColor);
    }
    return image;
}

int main() {
    vector<vector<int>> image = {{0, 1, 0},{1,1,0},{0,0,1}};
    int sr = 2, sc = 2, newColor = 3;
    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}