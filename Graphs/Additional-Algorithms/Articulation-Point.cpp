#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

   int timer = 0;
   void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], set<int> &stt) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(auto itr : adj[node]) {
        if(itr == parent) {
            continue;
        }

        if(!vis[itr]) {
            dfs(itr, node, vis, tin, low, adj, stt); 
            low[node] = min(low[node], low[itr]);
        } else {
            low[node] = min(low[node], tin[itr]);
        }
    }
    for(auto itr : adj[node]) {
        if(low[itr] > tin[node]) {
            stt.insert(itr);
            break;
        }
    }
   }

public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        set<int> stt;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, adj, stt);
            }
        }
        if(stt.size() == 0) {
            return {-1};
        }
        for(auto itr : stt) {
            ans.push_back(itr);
        }
        return ans;
    }
};

int main() {
    vector<int> adj[7] = {{1, 2, 3}, {0}, {0, 3, 4, 5}, {2, 0}, {2, 6}, {2, 6}, {4, 5}};
    // vector<int> adj[5] = {{1}, {0, 4}, {3, 4}, {2, 4}, {1, 2, 3}};
    vector<int> ans = Solution().articulationPoints(7, adj);
    for(auto itr : ans) {
        cout << itr << " ";
    }
    return 0;
}