#include <bits/stdc++.h>
using namespace std;


void bfsForGraph(int node, vector<int> adj[], int vis[], vector<int> &ans){
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto itr : adj[node]){
            if(!vis[itr]){
                vis[itr] = 1;
                q.push(itr);
            }
        }
    }
    return;
}

vector<int> BFS(int V, vector<int> adj[]){
    int vis[V] = {0};
    vector<int> ans;

    for(int i = 0; i < V; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            bfsForGraph(i, adj, vis, ans);
        }
    }

    return ans;
}


void dfsForGraph(int node, vector<int> adj[], int vis[], vector<int> &ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto itr : adj[node]){
        if(!vis[itr]){
            dfsForGraph(itr, adj, vis, ans);
        }
    }
    return;
}



void DFS(int V, vector<int> adj[]){
    int vis[V] = {0};
    vector<int> ans;

    for(int i = 0; i < V; i++){
        dfsForGraph(i, adj, vis, ans);
    }
}

int main() {
    return 0;
}