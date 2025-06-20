#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, size;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
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

        if(ulp_u == ulp_v) {
            return;
        }

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m, vector<vector<int>> &grid) {
        if(row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0) {
          return false;
        }
        return true;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    for(int k = 0; k < 4; k++) {
                        int nRow = i + dx[k];
                        int nCol = j + dy[k];
                        if(isValid(nRow, nCol, n, m, grid)) {
                            int nodeNo = i * m + j;
                            int adjNodeNo = nRow * m + nCol;
                            if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                                ds.unionBySize(nodeNo, adjNodeNo);
                            }
                        }
                    }
                }
            }
        }
        int maxSize = 0;
        for(int i = 0; i < ds.size.size(); i++) {
            maxSize = max(ds.size[i], maxSize);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    set<int> uniqueParents;
                    int size = 1;
                    for(int k = 0; k < 4; k++) {
                        int nRow = i + dx[k];
                        int nCol = j + dy[k];
                        if(isValid(nRow, nCol, n, m, grid)) {
                            int adjNode = nRow * m + nCol;
                            int parent = ds.findUPar(adjNode);
                            if(uniqueParents.find(parent) == uniqueParents.end()) {
                                size += ds.size[parent];
                                uniqueParents.insert(parent);
                            }
                        }
                    }
                    maxSize = max(size, maxSize);
                }
            }
        }
        return maxSize;
    }
};


int main() {
    // vector<vector<int>> grid = { {1,0, 1, 1}, {1, 1, 0, 0}, {1, 0, 1, 1}, {0, 1, 1, 1} };
    vector<vector<int>> grid = { {1, 1}, {1, 1}};
    cout << Solution().largestIsland(grid) << endl;
    return 0;
}