#include <bits/stdc++.h>
using namespace std;

class Dijisktra {
    public:
    // using priority_queue to store the distance and the node
    vector<int> shortestPath1(vector<vector<int>> adj[], int src, int V) {
        vector<int> dis(V);
        for(int i = 0; i < V; i++) dis[i] = 1e9;

        dis[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, src});

        while(!pq.empty()) {
            auto[dist, node] = pq.top();
            pq.pop();

            for(auto itr : adj[node]) {
                int adjNode = itr[0];
                int weight = itr[1];
                if(dist + weight < dis[adjNode]) {
                    dis[adjNode] = dist + weight;
                    pq.push({dist + weight, adjNode});
                }
            }
        }
        return dis;
    }

    vector<int> shortestPath2(vector<vector<int>> adj[], int src, int V) {
        vector<int> dis(V, 1e9);
        dis[src] = 0;
        set<pair<int, int>> stt;

        stt.insert({0, src});

        while(!stt.empty()) {
            auto itr = *(stt.begin());
            auto[dist, node] = itr;
            stt.erase(itr);

            for(auto it : adj[node]) {
                int adjNode = it[0];
                int wt = it[1];

                if(dist + wt < dis[adjNode]) {
                    if(dis[adjNode] != 1e9) stt.erase(stt.find({dis[adjNode], adjNode}));
                    dis[adjNode] = dist + wt;
                    stt.insert({dis[adjNode], adjNode});
                }
            }
        }
        return dis;
    }

};

int main() {
    vector<vector<int>> adj[6] = {{{1,4}, {2,4}}, {{0,4},{2,2}}, {{0,4},{1,2},{3,3},{4,1},{5,6}}, {{2,3},{5,2}}, {{2,1},{5,3}}, {{2,6},{3,2},{4,3}}};
    vector<int> ans = Dijisktra().shortestPath2(adj, 0, 6);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}