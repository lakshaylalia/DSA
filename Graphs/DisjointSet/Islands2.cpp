#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>
class DisjointSet {
public:
    vector<vector<P>> parent;
    vector<vector<int>> size;

    DisjointSet(int n, int m) {
        size.resize(n, vector<int>(m, 1));
        parent.resize(n, vector<P>(m, {0, 0}));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                parent[i][j] = {i, j};
            }
        }
    }

P findUPar(const P &a) {
    int x = a.first, y = a.second;
    auto par = parent[x][y];
    int Xpar = par.first, Ypar = par.second;
    if (Xpar == x && Ypar == y) {
        return {x, y};
    }
    return parent[x][y] = findUPar({Xpar, Ypar});
}


void unionBySize(P &a, P &b) {
    P ulp_a = findUPar(a);
    P ulp_b = findUPar(b);

    if (ulp_a == ulp_b) return;

    if (size[ulp_a.first][ulp_a.second] < size[ulp_b.first][ulp_b.second]) {
        parent[ulp_a.first][ulp_a.second] = ulp_b;
        size[ulp_b.first][ulp_b.second] += size[ulp_a.first][ulp_a.second];
    } else {
        parent[ulp_b.first][ulp_b.second] = ulp_a;
        size[ulp_a.first][ulp_a.second] += size[ulp_b.first][ulp_b.second];
    }
}

};

class Solution {
private:
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    bool isValid(int row, int col, int n, int m, vector<vector<int>> &grid) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
            return false;
        }
        return true;
    }


public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> ans;
        int totalIslands = 0;
        DisjointSet ds(n, m);
        for(int i = 0; i < A.size(); i++) {
            int row = A[i][0], col = A[i][1];
            if(grid[row][col] == 0) {
                grid[row][col] = 1;
                totalIslands++;
                for(int i = 0; i< 4; i++) {
                    int nRow = row + dx[i], nCol = col + dy[i];
                    if(isValid(nRow, nCol, n, m, grid)) {
                        P a = {row, col}, b = {nRow, nCol};
                        P pa = ds.findUPar(a), pb = ds.findUPar(b);
                        if(pa != pb) {
                          ds.unionBySize(pa, pb);
                          totalIslands--;
                        }
                    }
                }
            }
            ans.push_back(totalIslands);
        }
        return ans;
    }
};

int main() {
    int n = 2, m = 2;
    // vector<vector<int>> A = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0 ,3}, {1 ,3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};
    vector<vector<int>> A = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, A);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}














// #include <bits/stdc++.h>
// using namespace std;

// class DisjointSet {
// public:
//     /* To store the ranks, parents and 
//     sizes of different set of vertices */
//     vector<int> rank, parent, size;

//     // Constructor
//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }
    
//     // Function to find ultimate parent
//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }
    
//     // Function to implement union by rank
//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }
    
//     // Function to implement union by size
//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// // Solution class
// class Solution{
// private:
//     vector<int> delRow = {-1, 0, 1, 0};
//     vector<int> delCol = {0, 1, 0, -1};

//     bool isValid(int &i, int &j, int &n, int &m) {
//         if(i < 0 || i >= n) return false;
//         if(j < 0 || j >= m) return false;
//         return true;
//     }
    
// public:
//     vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
                                 
//         DisjointSet ds(n * m);
        
//         int vis[n][m];
//         memset(vis, 0, sizeof vis);

//         int cnt = 0;
//         vector<int> ans;
//         for (auto it : A) {
//             int row = it[0];
//             int col = it[1]; 
//             if (vis[row][col] == 1) {
//                 ans.push_back(cnt);
//                 continue;
//             }
            
//             vis[row][col] = 1;
            
//             cnt++;
            
//             for (int ind = 0; ind < 4; ind++) {
//                 int newRow = row + delRow[ind];
//                 int newCol = col + delCol[ind];
                
//                 if (isValid(newRow, newCol, n, m) && 
//                     vis[newRow][newCol] == 1) {
                    
//                     int nodeNo = row * m + col;
//                     int adjNodeNo = newRow * m + newCol;
//                     if (ds.findUPar(nodeNo) != 
//                         ds.findUPar(adjNodeNo)) {
//                         cnt--;
//                         ds.unionBySize(nodeNo, adjNodeNo);
//                     }
//                 }
//             }
//             ans.push_back(cnt);
//         }

//         return ans;
//     }
// };
