#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   void bfs(vector<vector<int>>& adj, vector<int>& indegree, queue<int> &q, int &count) {
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(auto itr : adj[node]){
            indegree[itr]--;
            if(indegree[itr] == 0){
                q.push(itr);
            }
        
        }
    }
   }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int count = 0;
        bfs(adj, indegree, q, count);
        if(count == numCourses) return true;
        return false;
    }
};

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << Solution().canFinish(numCourses, prerequisites) << endl;
    return 0;
}