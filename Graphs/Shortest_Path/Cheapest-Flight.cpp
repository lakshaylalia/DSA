#include <bits/stdc++.h>
using namespace std;

#define P pair<int, pair<int, int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto itr : flights) {
            int u = itr[0], v = itr[1], wt = itr[2];
            adj[u].push_back({v, wt});
        }
       vector<int> minDist(n, 1e9);
        queue <P> q;
        q.push({0, {src, 0}});

        while(!q.empty()) {

            auto p = q.front();
            q.pop();
            int stops = p.first; 
            int node = p.second.first; 
            int dist = p.second.second;

            if(stops > k) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                if(dist + edgeWt < minDist[adjNode] && stops <= k) {
                    minDist[adjNode] = dist + edgeWt;
                    q.push({stops+1, {adjNode, dist + edgeWt}});
                }
            }
        }
        if(minDist[dst] == 1e9) return -1;
        return minDist[dst];
    }
};


int main() {
    int n = 13;
      vector<vector<int>> flights = {
        {11,12,74},{1,8,91},{4,6,13},{7,6,39},{5,12,8},{0,12,54},{8,4,32},{0,11,4},
        {4,0,91},{11,7,64},{6,3,88},{8,5,80},{11,10,91},{10,0,60},{8,7,92},{12,6,78},
        {6,2,8},{4,3,54},{3,11,76},{3,12,23},{11,6,79},{6,12,36},{2,11,100},{2,5,49},
        {7,0,17},{5,8,95},{3,9,98},{8,10,61},{2,12,38},{5,7,58},{9,4,37},{8,6,79},
        {9,0,1},{2,3,12},{7,10,7},{12,10,52},{7,2,68},{12,2,100},{6,9,53},{7,4,90},
        {0,5,43},{11,2,52},{11,8,50},{12,4,38},{7,9,94},{2,7,38},{3,7,88},{9,12,20},
        {12,0,26},{10,5,38},{12,8,50},{0,2,77},{11,0,13},{9,10,76},{2,6,67},{5,6,34},
        {9,7,62},{5,3,67}
    };
    cout << Solution().findCheapestPrice(n, flights, 10, 1, 10) << endl;
    return 0;
}