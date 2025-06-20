#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& adj,vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for (auto itr : adj[node]) {
            if (itr == parent) {
                continue;
            }
            if (!vis[itr]) {
                dfs(itr, node, vis, tin, low, adj, bridges);
                low[node] = min(low[node], low[itr]);
                if (low[itr] > tin[node]) {
                    bridges.push_back({node, itr});
                }
            } else {
                low[node] = min(low[node], low[itr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto itr : connections) {
            int u = itr[0], v = itr[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;
        dfs(0, -1, vis, tin, low, adj, bridges);
        return bridges;
    }
};


int main() {
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector< vector<int>> result = Solution().criticalConnections(4, connections);
    for(auto itr : result) {
        for(auto ptr : itr) {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}