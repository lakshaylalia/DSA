#include <bits/stdc++.h>
using namespace std;

class Kahn{
    private:
    void bfs(vector<vector<int>> & adj, vector<int> &indegree, queue<int> &q, vector<int> &ans){
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
    }
    
    public:
    vector<int> topologicalSort(int V, vector<vector<int>> &adj){
        vector<int> indegree(V,0);
        
        for(int i = 0; i < V; i++){
            for(auto itr : adj[i]){
                indegree[itr]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        bfs(adj, indegree, q, ans);
        return ans;
    }
};

int main() {
    vector<vector<int>> adj = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<int> ans = Kahn().topologicalSort(6, adj);
    for(auto itr : ans) cout << itr <<" ";
    return 0;
}