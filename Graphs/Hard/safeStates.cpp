#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
 bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &path, vector<int> &check){
    vis[node] = 1;
    path[node] = 1;
    check[node] = 0;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, path, check)) return true;
        } else if(path[it]) return true;
    }
    check[node] = 1;
    path[node] = 0;
    return false;
 }

public:
 vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    vector<int> check(V, 0);
    vector<int> vis(V, 0);
    vector<int> path(V, 0);
    vector<int> ans;
    for(int  i = 0; i < V; i++){
        if(!vis[i]) dfs(i, adj, vis, path, check);
    }

    for(int i = 0; i < V; i++){
        if(check[i] == 1) ans.push_back(i);
    }
    return ans;
 }
};

int main() {
    int n = 7;
    vector<int> adj[n] = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> ans = Solution().eventualSafeNodes(n, adj);
    for(auto it : ans) cout << it << " ";
    return 0;
}