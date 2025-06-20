#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &stt) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                dfs(adjNode, vis, adj, stt);
            }
        }
        stt.push(node);
    }

    void helperDfs(int node, vector<int> &vis, vector<vector<int>> &adjT) {
        vis[node] = 1;
        for (auto adjNode : adjT[node]) {
            if (!vis[adjNode]) {
                helperDfs(adjNode, vis, adjT);
            }
        }

    }

public:
    int numberOfComponents(vector<vector<int>> &adj, int V) {
        vector<int> vis(V, 0);
        stack<int> stt;
        // Step1 : Sorting according to finishing time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, stt);
            }
        }
           
        // Step 2 : Transpose the graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0;
            for (auto itr : adj[i]) {
                adjT[itr].push_back(i);
            }
        }

        // Step 3 : Count the number of strongly connected components
        int components = 0;
        while(!stt.empty()) {
            int node = stt.top();
            stt.pop();
            if(!vis[node]) {
                helperDfs(node, vis, adjT);
                components++;
            }
        }
        return components;
    }
};

int main() {
    vector<vector<int>> adj = {{1, 2}, {2, 3}, {4}, {}, {4}, {}};
    cout << Solution().numberOfComponents(adj, 5);
    return 0;
}