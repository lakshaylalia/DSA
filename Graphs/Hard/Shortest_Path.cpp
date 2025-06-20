#include <bits/stdc++.h>
using namespace std;


class Solution {
 private:
    void bfs(vector<vector<int>> &adj, vector<int> &shortestPath, vector<int> &vis, int src){
        queue<pair<int, int>> q;
        q.push({src, 0});
        vis[src] = 1;
        while(!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();
            for(auto adjNode: adj[node]) {
                if(!vis[adjNode]) {
                    vis[adjNode] = 1;
                    shortestPath[adjNode] = dist + 1;
                    q.push({adjNode, dist + 1});
                } else if(vis[adjNode]){
                    shortestPath[adjNode] = min(shortestPath[adjNode], dist + 1);
                }
            }
        }
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<vector<int>> adj(N);
        for(auto itr : edges){
            int u = itr[0], v = itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(N, 0);
        vector<int> shortestPath(N, INT_MAX);
        shortestPath[0] = 0;
        bfs(adj, shortestPath, vis, 0);
        for(auto &itr : shortestPath) {
            if(itr == INT_MAX) itr = -1;
        }
        return shortestPath;
    }
};


int main() {
    vector<vector<int>> edges = {{1, 0}, {2, 1}, {0, 3}, {3, 7}, {3, 4}, {7, 4}, {7, 6}, {4, 5}, {4, 6}, {6, 5}};
    vector<int> ans = Solution().shortestPath(edges, 8, 10);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}