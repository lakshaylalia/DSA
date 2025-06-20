#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
      vector<vector<int>> adj[n+1];
      for(auto itr : edges) {
        int u = itr[0], v = itr[1], wt = itr[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
      }
      vector<int> dis(n+1, 1e9);
      vector<int> path(n+1, -1);
      dis[1] = 0;
      path[1] = 1;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({1, 0});

      while(!pq.empty()){
        auto [node, dist] = pq.top();
        pq.pop();
        
        for(auto itr : adj[node]) {
            int adjNode = itr[0], wt = itr[1];
            if(dist + wt < dis[adjNode]) {
                dis[adjNode] = dist + wt;
                pq.push({adjNode, dis[adjNode]});
                path[adjNode] = node;
            }
        }
      }
      if(dis[n] == 1e9) return {-1};
      vector<int> ans;
      int val = n;
      while(val != 1) {
        ans.push_back(val);
        val = path[val];
      }
      ans.push_back(1);
      ans.push_back(dis[n]);
      reverse(ans.begin(), ans.end()); 
      return ans;
    }
};

int main() {
    vector<vector<int>> edges = {{1, 2, 2}};
    vector<int> ans = Solution().shortestPath(3, 1, edges);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}