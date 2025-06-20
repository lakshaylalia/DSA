#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(vector<vector<int>> & adj, vector<int> &indegree, queue<int> &q, vector<int> &ans){
        while(!q.empty()){
            int node  = q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode : adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

      vector<vector<int>> adj(numCourses);
        for (auto& edges : prerequisites) {
          int u = edges[1], v = edges[0];
          adj[u].push_back(v); 
        }


        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            for(auto itr : adj[i]){
                indegree[itr]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        bfs(adj, indegree, q, ans);
        if(ans.size() < numCourses) return {};
        return ans;
    }
};

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> ans = Solution().findOrder(numCourses, prerequisites);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}