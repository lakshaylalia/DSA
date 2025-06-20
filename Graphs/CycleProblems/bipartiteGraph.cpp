#include <bits/stdc++.h>
using namespace std;

class Solution{
private:

    bool bfs(vector<vector<int>>& graph, int src, vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : graph[node]){
                if(color[adjNode] == -1){
                    int col = (color[node] == 0) ? 1 : 0;
                    color[adjNode] = col;
                    q.push(adjNode);
                }
                else if(color[node] == color[adjNode]){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph){
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                if(!bfs(graph, i, color)) return false;
            }
        }
        return true;
    }
};


int main() {
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout <<Solution().isBipartite(graph) << endl;
    return 0;
}