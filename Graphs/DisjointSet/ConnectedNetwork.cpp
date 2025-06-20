#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += ulp_v;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);

        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            ds.unionBySize(u, v);
        }

        int totalComponents = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) totalComponents++;
        }

        if(totalComponents == 0) return 0;
        return totalComponents-1;
    }
};

int main() {
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
    cout << Solution().makeConnected(5, connections) << endl;
    return 0;
}