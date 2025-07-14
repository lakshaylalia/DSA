#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool dfs(int src, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]){
        vis[src] = 1;
        pathVis[src] = 1;

        for(auto itr : adj[src]){
            if(!vis[itr]){
                if(pathVis[itr]) {
                    return true;
                }
                else if(dfs(itr, vis, pathVis, adj)) {
                    return true;
                }
            }
        }
        pathVis[src] = 0;
        return false;
    }
    void bfs(vector<int> adj[], vector<int> &indegree, queue<int> &q, vector<int> &ans){
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
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++){
            for(auto itr : adj[i]) indegree[itr]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i< N; i++){
            if(indegree[i] == 0) q.push(i);
        }
        bfs(adj, indegree, q, ans);
        if(ans.size()  < N) return true;
        return false;
    }
};

int main() {
    int V = 4;
    vector<int> adj[4] = {{1, 2}, {2}, {0}, {0, 2}};
    cout << "Is there a cycle in the graph? " << Solution().isCyclic(V, adj);
    return 0;
}