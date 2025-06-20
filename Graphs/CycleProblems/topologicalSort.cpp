#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stt){
        vis[node] = 1;
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, vis, adj, stt);
            }
        }
        stt.push(node);
    }
    public:
    vector<int> topoSort(int V, vector<vector<int>> adj){
        vector<int> vis(V, 0);
        vector<int> ans;
        stack<int> stt;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, stt);
            }
        }
        while(!stt.empty()){
            ans.push_back(stt.top());
            stt.pop();
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> ans = Solution().topoSort(6, adj);
    for(auto itr : ans) cout << itr <<" ";
    return 0;
}