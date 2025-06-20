#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool bfs(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        queue<pair<int, int>> q;

        q.push({src, -1});

        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                } else if(adjNode != par){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int src, vector<int> adj[], vector<int> &vis, int par){
        vis[src] = 1;
        for(auto adjNode : adj[src]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, src)) return true;
            }
            else if(adjNode != par) return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, -1)) return true;
                // if(bfs(i, adj, vis)) return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 6;
    vector<int> adj[V] = {{1,3}, {0,2,4}, {1,5},{0,4}, {1,3,5}, {2,4}};
    cout << Solution().isCycle(V, adj) << endl;
    return 0;
}