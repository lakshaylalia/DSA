#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;

    for(auto itr : adj[node]){
        if(!vis[itr]){
            dfs(itr, adj, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();
    vector<int> adj[V + 1];     
    vector<int> vis(V + 1, 0);

    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }

    int connected = 0;
    for(int i = 1; i <= V; i++) {
        if(vis[i] == 0) {
            connected++;
            dfs(i, adj, vis);
        }
    }

    return connected;
}

int main() {
    vector<vector<int>> isConnected = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
};
    int ans = findCircleNum(isConnected);
    cout << ans << endl;
    return 0;
}