#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void topoSort(vector<vector<char>>& adj, vector<int>& inDegree,queue<int> &q, string &s){
        while(!q.empty()){
            int val = q.front();
            q.pop();
            s.push_back(val + 'a');
            for(auto itr : adj[val]){
                int idx = itr - 'a';
                inDegree[idx]--;
                if(inDegree[idx] == 0) q.push(idx);
            }
        }
    }
public:
	string findOrder(string dict[], int N, int K) {
		vector<vector<char>> adj(K);
        for(int i = 0; i < N - 1; i++){
          int j = i + 1, k = 0;
          while(k < dict[i].size() && k < dict[j].size() && dict[i][k] == dict[j][k]) k++;
            if(k < dict[i].size() && k < dict[j].size()){
              int idx = dict[i][k] - 'a';
              adj[idx].push_back(dict[j][k]);
            }
        }

        vector<int> inDegree(K, 0);
        for(int i = 0; i < K; i++){
            for(auto itr : adj[i]){
                int idx = itr - 'a';
                inDegree[idx]++;
            }
        }
        queue<int> q;
        string ans= "";
        for(int i = 0; i < K; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        topoSort(adj, inDegree, q, ans);
        return ans;
	}
};


int main() {
    string dict[] = {"abc", "bca", "cab"};
    cout << Solution().findOrder(dict, 3, 3);
    return 0;
}