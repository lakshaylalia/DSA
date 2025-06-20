#include <bits/stdc++.h>
using namespace std;

#define P pair<long long,int>

class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = 1e9 + 7; 
        
        vector<pair<int,int>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        vector<long long> minTime(n, LLONG_MAX);

        vector<int> ways(n, 0);

        priority_queue <P, vector<P>, greater<P>> pq;

        minTime[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {

            auto p = pq.top(); 
            pq.pop();

            
            long long time = p.first;
            int node = p.second;

            if(time > minTime[node]) continue;

            for(auto it : adj[node]) {
                
                int adjNode = it.first;
                int travelTime = it.second; 

                if(minTime[adjNode] > time + travelTime) {
                    
                    
                    minTime[adjNode] = time + travelTime;
                    
                    ways[adjNode] = ways[node];
                    
                    pq.push({minTime[adjNode] , adjNode});
                }
 
                else if(minTime[adjNode] == time + travelTime) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

int main() {
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    // vector<vector<int>> roads = {{1, 0, 10}};
    cout << Solution().countPaths(7, roads);
    return 0;
}