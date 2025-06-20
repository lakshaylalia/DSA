#include<bits/stdc++.h>
using namespace std;

void subset(int idx, int sum,vector<int> &ans, vector<int> &arr){
    if(idx >= arr.size()){
        ans.push_back(sum);
        return;
    }
    subset(idx + 1, sum + arr[idx], ans, arr);
    subset(idx + 1 , sum, ans, arr);
}

vector<int> sunSet1(vector<int> &arr, vector<int> &ans){
    subset(0, 0, ans, arr);
    sort(ans.begin(), ans.end());
    return ans; 
}

int upperBound(int num, vector<int> &arr){
    int  low = 0;
    int  high = arr.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid =(low + high)/2;
        if(arr[mid] > num){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

void subSet2(int idx, vector<int> &ds, vector<vector<int>> &ans, vector<int> &arr){
    if(idx == arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = idx ; i < arr.size() ; i++){
        ds.push_back(arr[i]);
        subSet2(i + 1, ds, ans, arr);
        ds.pop_back();
        i = upperBound(arr[i], arr);
        if (i == -1) break;
        else i = i - 1;
    }
    ans.push_back(ds);
}


void letterCombo(int idx, string s,string digits, vector<string>&ans, vector<string>&combo){
    if(idx == digits.size()){
        ans.push_back(s);
        return;
    }

    int el = digits[idx] - '0';
    for(int i = 0 ; i < combo[el].size()  ; i++){
        letterCombo(idx + 1, s + combo[el][i], digits, ans, combo);
    }
}

vector<string> letterCombinations(string digits, vector<string>&ans){
    vector<string> combo = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    letterCombo(0, "", digits, ans, combo);
    return ans;
}

void func(int n, int &count, int row, int col, set<pair<int,int>> &stt) {
    if(stt.find({row, col}) != stt.end()) return;
    count += 1;
    stt.insert({row, col});
    
    if(n == 1) return;
    
    func(n - 1, count, row - 1, col, stt);
    func(n - 1, count, row + 1, col, stt);
    func(n - 1, count, row, col - 1, stt);
    func(n - 1, count, row, col + 1, stt);
}


int main(){
//     vector<string> ans;
//     vector<string> result = letterCombinations("23", ans);
//     cout << ans.size() << endl;
//    for(auto itr : ans) cout << itr << " ";
    int n;
    cin >> n;
    int count = 0;
    set<pair<int,int>> stt;
    func(n, count, 0, 0, stt);
    cout << count << endl;
    return 0;
}