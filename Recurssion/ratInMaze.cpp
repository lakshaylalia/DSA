#include<bits/stdc++.h>
using namespace std;


void path(int row, int col, string str, vector<string> &ans, set<pair<int,int>> &stt, vector<vector<int>> &mat){
    if(mat[row][col] == 0) return;

    if(row == mat.size() - 1 && col == mat.size() - 1){
        ans.push_back(str);
        return;
    }

    if(row + 1 <= mat.size() - 1 && mat[row + 1][col] == 1){
        if (stt.find({row + 1, col}) == stt.end()){
            stt.insert({row + 1, col});
            path(row + 1, col, str + 'D', ans, stt, mat);
            stt.erase({row + 1, col});
        }
    }

    if(col + 1 <= mat.size() - 1 && mat[row][col + 1] == 1){
        if (stt.find({row, col + 1}) == stt.end()){
            stt.insert({row , col + 1});
            path(row, col + 1, str + 'R', ans, stt, mat);
            stt.erase({row, col + 1});
        }
    }

    if(row - 1 >= 0 && mat[row][col - 1] == 1){
        if (stt.find({row, col - 1}) == stt.end()){
            stt.insert({row, col - 1});
            path(row, col - 1, str + 'L', ans, stt, mat);
            stt.erase({row, col - 1});
        }
    }

    if(row - 1 >= 0 && mat[row - 1][col] == 1){
        if (stt.find({row -1 , col}) == stt.end()){
            stt.insert({row - 1, col});
            path(row - 1, col, str + 'U', ans, stt, mat);
            stt.erase({row - 1, col});
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat, vector<string> &ans){
    if(mat.size() == 0 || mat[mat.size() - 1][mat.size() - 1] == 0) return ans;
    set<pair<int,int>> stt = {{0,0}};
    path(0, 0, "", ans, stt, mat);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 1, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}};
    vector<string> ans;
    findPath(mat, ans);
    sort(ans.begin(), ans.end());
    // cout << ans.size();
    for(auto itr : ans) cout << itr << " " << endl;
    return 0;
}