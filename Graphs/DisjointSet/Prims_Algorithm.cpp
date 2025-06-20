#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>
class Solution{
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int totalWeight = 0;
        vector<int> vis(V, 0);
        vector<tuple<int, int, int>> mstEdges;
        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

        pq.push({0, {0, -1}});

        while (!pq.empty()) {
            auto [wt, p] = pq.top();
            auto [node, parent] = p;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            totalWeight += wt;

            if (parent != -1) {
                mstEdges.push_back({parent, node, wt});
            }

            for (auto &itr : adj[node]) {
                int adjNode = itr[0], edgeWt = itr[1];
                if (!vis[adjNode]) {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }

        return totalWeight;
    }
};



int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };
    
    vector<vector<int>> adj[4];
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    cout << Solution().spanningTree(V, adj);
    
    return 0;
}