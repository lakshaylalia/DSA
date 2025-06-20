#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int adjMatrix[n+1][n+1] = {0};
    for(int i = 0; i < m ; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }


    vector<int> adjList[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return 0;
}