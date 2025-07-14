#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void topoSort(vector<vector<pair<int,int>>> adj, vector<int> &inDegree, vector<int> &topo, queue<int> &q){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto itr : adj[node]){
                int neighbour = itr.first;
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) q.push(neighbour);
            }
        }
    }
    public:
    vector<int> shortestPath(int N, int M, vector < vector < int >> & edges) {
        vector<vector<pair<int,int>>> adj(N);

        for(auto itr : edges){
            int u = itr[0], v = itr[1], wt = itr[2];
            adj[u].push_back({v, wt});
        }
        vector<int> inDegree(N, 0);
        for(int i = 0; i < N; i++){
            for(auto itr : adj[i]){
                int v = itr.first;
                inDegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        topoSort(adj, inDegree, topo, q);
        
        vector<int> shortestPath(N, INT_MAX);
        shortestPath[0] = 0;
        for(int i : topo){
            for(auto itr : adj[i]){
                int v = itr.first, wt = itr.second;
                if(shortestPath[i] != INT_MAX && shortestPath[i] + wt < shortestPath[v]){
                    shortestPath[v] = shortestPath[i] + wt;
                }
            }
        }

        for(auto &itr : shortestPath){
            if(itr == INT_MAX) itr = -1;
        }
        return shortestPath;
    }
};



int main() {
    int N = 6, M = 7;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 1}, {4, 5, 4}, {4, 2, 2}, {1, 2, 3}, {2, 3, 6}, {5, 3, 1}};
    vector<int> ans = Solution().shortestPath(N, M, edges);
    for(auto itr : ans) cout << itr << " "; 
    return 0;
}