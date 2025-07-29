#include <bits/stdc++.h>
using namespace std;

// bool dfs(int node, int par, vector<int> &vis, vector<vector<int>> &adj) {
//     vis[node] = 1;
//     for(auto itr : adj[node]) {
//         if(!vis[itr]) {
//             if(dfs(itr, node, vis, adj)) {
//                 return true;
//             }
//         } else if(itr != par) {
//             return true;
//         }
//     }
//     return false;
// }

// bool bfs(int src, vector<int> &vis, vector<vector<int>> &adj) {
//     vis[src] = 1;
//     queue<pair<int, int>> q;
//     q.push({src, -1});
//     while(!q.empty()) {
//         auto [node, par] = q.front();
//         for(auto itr : adj[node]) {
//             if(!vis[itr]) {
//                 vis[itr] = 1;
//                 q.push({itr, node});
//             } else if(itr != par) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// bool dfs(int src, vector<bool> &vis, vector<int> &color, vector<vector<int>> &adj) {
//     vis[src] = true;
//     for(auto itr : adj[src]) {
//         if(!vis[itr]) {
//             int nCol = color[src] == 0 ? 1 : 0;
//             color[itr] = nCol;
//             vis[itr] = true;
//             if(dfs(itr, vis, color, adj)) {
//                 return true;
//             }
//         } else if(color[itr] == color[src]) {
//             return true;
//         }
//     }
//     return false;
// }

// bool func(vector<vector<int>> &adj, int n) {
//     vector<int> color(n, -1);
//     vector<bool> vis(n, false);
//     for(int i = 0; i < n; i++) {
//         if(!vis[i]) {
//             color[i] = 1;
//             if(dfs(i, vis, color, adj)) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// void dfs(int node, vector<bool> &vis, vector<int> &ans, vector<vector<int>> &adj) {
//     vis[node] = true;
//     for(auto  itr : adj[node]) {
//         if(!vis[itr]) {
//             dfs(itr, vis, ans, adj);
//         }
//     }
//     ans.push_back(node);
// }


// vector<int> topoSort(vector<vector<int>> &adj, int n) {
//     vector<bool> vis(n, 0);
//     vector<int> ans;
//     for(int i = 0; i < n; i++) {
//         if(!vis[i]) {
//             dfs(i, vis, ans, adj);
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }


// vector<int> khanAlgorithm(vector<vector<int>> &adj, int n) {
//     vector<int> indegree(n, 0);
//     for(int i = 0; i < n; i++) {
//         for(auto itr : adj[i]) {
//             indegree[itr]++;
//         }
//     }
//     queue<int> q;
//     for(int i = 0; i < n; i++) {
//         if(indegree[i] == 0) {
//             q.push(i);
//         }
//     }
//     vector<int> ans;
//     while(!q.empty()) {
//         int node = q.front();q.pop();
//         ans.push_back(node);
//         for(auto itr : adj[node]) {
//             indegree[itr]--;
//             if(indegree[itr] == 0) {
//                 q.push(itr);
//             }
//         }
//     }
//     return ans;
// }

// bool dfs(int src, vector<int> &vis, vector<int> &path, vector<vector<int>> &adj) {
//     vis[src] = 1;
//     path[src] = 1;
//     for(auto itr : adj[src]) {
//         if(!vis[itr]) {
//             if(dfs(itr, vis, path, adj)) {
//                 return true;
//             }
//         } else if(path[itr]) {
//             return true;
//         }
//     }
//     path[src] = 0;
//     return false;
// }


// bool isDAG(vector<vector<int>> &adj, int n) {
//     vector<int> vis(n, 0);
//     vector<int> path(n, 0);
//     for(int i = 0; i < n; i++) {
//         if(!vis[i]) {
//             if(dfs(i, vis, path, adj)) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int wordLadder1(string beginWord, string endWord, vector<string>& wordList) {
//     if(beginWord == endWord) {
//         return 0;
//     }
//     queue<pair<string, int>> q;
//     unordered_set<string> stt(wordList.begin(), wordList.end());
//     stt.erase(beginWord);
//     q.push({beginWord, 1});
//     while(!q.empty()) {
//         auto [word, steps] = q.front();q.pop();
//         if(word == endWord) {
//             return steps;
//         }
//         for(int i = 0; i < word.size(); i++) {
//             char orignal = word[i];
//             for(char ch = 'a'; ch <= 'z'; ch++) {
//                 word[i] = ch;
//                 if(stt.find(word) != stt.end()) {
//                     q.push({word, steps + 1});
//                     stt.erase(word);
//                 }
//             }
//             word[i] = orignal;
//         }
//     }
//     return 0;
// }


// vector<int> Dijkstra(vector<vector<vector<int>>> &adj, int n, int src) {
//     vector<int> dis(n, 1e9);
//     vector<int> par(n);
//     for(int i = 0; i < n; i++) {
//         par[i] = i;
//     }
//     dis[src] = 0;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     pq.push({0, src});
//     while(!pq.empty()) {
//         auto [dist, node] = pq.top();pq.pop();
//         for(auto itr : adj[node]) {
//             auto adjNode = itr[0], adjDist = itr[1];
//             if(dist + adjDist < dis[adjNode]) {
//                 dis[adjNode] = dist + adjDist;
//                 pq.push({dis[adjNode], adjNode});
//                 par[adjNode] = node;
//             }
//         }
//     }
    
//     return dis;
// }


// vector<vector<int>> floydWarshall(vector<vector<int>> &adj, int n) {
//     vector<vector<int>> dis(n, vector<int>(n, 1e9));
//     for(int i = 0; i < n; i++) {
//         dis[i][i] = 0;
//     }

//     for(int k = 0;  k <n; k++) {
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < n; j++) {
//                 dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//             }
//         }
//     }
//     return dis;
// }


// class DisJointSet {
// public:
//     vector<int> parent, size;
//     DisJointSet(int n) {
//         size.resize(n + 1, 1);
//         parent.resize(n + 1);
//         for(int i = 1; i <= n; i++) {
//             parent[i] = i;
//         }
//     }

//     int findUPar(int node) {
//         if(node == parent[node]) {
//             return node;
//         }
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) {
//             return;
//         } else if(size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         } else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }

//     bool find(int u, int v) {
//         if(findUPar(u) == findUPar(v)) {
//             return true;
//         } 
//         return false;
//     }
// };

int timer = 0;

void dfs(int node, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, int parent, vector<vector<int>> &bridges) {
    vis[node] = true;
    tin[node] = low[node] = timer++;
    for(auto itr : adj[node]) {
        if(itr == parent) {
            continue;
        }
        if(!vis[itr]) {
            dfs(itr, vis, tin, low, adj, node, bridges);
            low[node] = min(low[node], low[itr]);
            if(low[itr] > tin[node]) {
                bridges.push_back({node, itr});
            } else {
                low[node] = min(low[node], low[itr]);
            }
        }
    }
}


vector<vector<int>> Tarjan(vector<vector<int>> &adj, int n) {
    vector<int> tin(n, -1), low(n, -1), vis(n, 0);
    vector<vector<int>> bridges;
    dfs(0, vis, tin, low, adj, -1, bridges);
    return bridges;
}



int main() {
    
    return 0;
}