#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dis(V, 1e9);
        dis[S] = 0;

        for(int i = 0; i < V - 1; i++) {
            for(auto itr : edges) {
                int u = itr[0], v = itr[1], wt = itr[2];
                if(dis[u] != 1e9 && dis[u] + wt < dis[v]) {
                    dis[v] = dis[u] + wt;
                }
            }
        }

        // check for negative weight cycle
        for(auto itr : edges) {
            int u = itr[0], v = itr[1], wt = itr[2];
            if(dis[u] != 1e9 && dis[u] + wt < dis[v]) {
                return {-1}; // negative cycle exists
            }
        }

        return dis;
    }
};



int main() {
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    vector<int> ans = Solution().bellman_ford(5, edges, 0);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}