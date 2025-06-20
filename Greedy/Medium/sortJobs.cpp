#include <bits/stdc++.h>
using namespace std;

 class Solution{
    private:
    bool static compare(vector<int> &a, vector<int> &b){
        return a[2] > b[2];
    }

    public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        sort(Jobs.begin(), Jobs.end(), compare);
        int maxDeadline = -1;
        for(auto itr : Jobs) maxDeadline = max(maxDeadline, itr[1]);

        int cnt = 0, profit = 0;
        vector<int> schedule(maxDeadline + 1, -1);

        for(int i = 0; i < Jobs.size(); i++){
            for(int j = Jobs[i][1]; j >= 0; j--){
                if(schedule[j] == -1){
                    schedule[j] = 1;
                    cnt++;
                    profit += Jobs[i][2];
                    break;
                }
            }
        }
        return vector<int>{cnt, profit};
    }
 };

int main() {
    vector<vector<int>> Jobs = {{1, 2, 50}, {3, 1, 10}, {2, 4, 75}};
    vector<int> ans = Solution().JobScheduling(Jobs);
    for(auto itr : ans) cout << itr <<" ";
    return 0;
}