#include<bits/stdc++.h>
using namespace std;

void combination(int k, int n, vector<int> &ds,vector<vector<int>> &ans){
    if(ds.size() == k && n == 0){
        ans.push_back(ds);
        return;
    }
    if((n < 0) || (ds.size() > k)) return;
    int el = ds.empty() ? 1 : ds[ds.size() - 1] + 1;
    for(int i = el ; i <= 9 ; i++){
        if(i <= n){
            ds.push_back(i);
            combination(k, n - i, ds, ans);
            ds.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n, vector<vector<int>> &ans){
    vector<int> ds;
    combination(k, n, ds, ans);
    return ans;
}

void generateString(string s, vector<string> &ans, int num){
    if(s.size() == num){
        ans.push_back(s);
        return;
    }
    s.push_back('0');
    generateString(s, ans, num);
    s.pop_back();

    if(s[s.size() - 1] != '1'){
        s.push_back('1');
        generateString(s, ans, num);
        s.pop_back();
    }
}

vector<string> generateBinaryStrings(int num, vector<string>&ans){
    generateString("", ans, num);
    return ans;
}

int main(){
    // vector<string> ans;
    // generateBinaryStrings(2, ans);
    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i]<< " ";
    // }
    vector<pair<int, int>> v = {{2,6},{2,5},{1,4},{1,3},{1,2},{1,1}};
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}