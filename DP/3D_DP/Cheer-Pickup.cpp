#include <bits/stdc++.h>
using namespace std;

// 1. Express everything in terms of (i1, j1) and (i2, j2) and add base case
// 2. Explore all the possible paths
// 3. Return the maximum value or mimumum value or any other value
class Solution {
private:
    int cherryPickupRecursive(int row, int col1, int col2, vector<vector<int>> &cherry) {
        int n = cherry.size(), m = cherry[0].size();
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) {
            return -1e8;
        }
        if(row == n-1) {
            if(col1 == col2) {
                return cherry[row][col1];
            } else {
                return cherry[row][col1] + cherry[row][col2];
            }
        }

        int maxi = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(col1 == col2) {
                    maxi = max(maxi, cherry[row][col1] + cherryPickupRecursive(row+1, col1+i, col2+j, cherry));
                } else {
                    maxi = max(maxi, cherry[row][col1] + cherry[row][col2] + cherryPickupRecursive(row+1, col1+i, col2+j, cherry));
                }
            }
        }
        return maxi;
    }
    int cherryPickupMemoization(int row, int col1, int col2, vector<vector<int>> &cherry, vector<vector<vector<int>>> &dp) {
        int n = cherry.size(), m = cherry[0].size();
        if(col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) {
            return -1e8;
        }
        if(row == n-1) {
            if(col1 == col2) {
                return cherry[row][col1];
            } else {
                return cherry[row][col1] + cherry[row][col2];
            }
        }
        if(dp[row][col1][col2] != -1) {
            return dp[row][col1][col2];
        }

        int maxi = 0;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(col1 == col2) {
                    maxi = max(maxi, cherry[row][col1] + cherryPickupRecursive(row+1, col1+i, col2+j, cherry));
                } else {
                    maxi = max(maxi, cherry[row][col1] + cherry[row][col2] + cherryPickupRecursive(row+1, col1+i, col2+j, cherry));
                }
            }
        }
        return dp[row][col1][col2] = maxi;
    }

   int cherryPickupTabulation(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n - 1][j1][j2] = matrix[n - 1][j1];
                } else {
                    dp[n - 1][j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
                }
                    
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = INT_MIN;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ans;

                            if (j1 == j2) {
                                ans = matrix[i][j1];
                            } else {
                                ans = matrix[i][j1] + matrix[i][j2];
                            }
                                

                            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m)) {
                                ans += -1e9;
                            }  else {
                                ans += dp[i + 1][j1 + di][j2 + dj]; 
                            }
                                
                            maxi = max(ans, maxi); 
                        }
                    }
                    dp[i][j1][j2] = maxi; 
                }
            }
        }
        return dp[0][0][m - 1];
    }

     int cherryPickSpaceOptimized(vector<vector<int>> &matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> cur(m, vector<int>(m, 0));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    front[j1][j2] = matrix[n - 1][j1];
                } else {
                    front[j1][j2] = matrix[n - 1][j1] + matrix[n - 1][j2];
                }
                    
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = INT_MIN;

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int ans;

                            if (j1 == j2) {
                                ans = matrix[i][j1];
                            } else {
                                ans = matrix[i][j1] + matrix[i][j2];
                            }
                                

                            if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m)) {
                                ans += -1e9;
                            } else {
                                ans += front[j1 + di][j2 + dj];
                            }
                             
                            maxi = max(ans, maxi); 
                        }
                    }
                    cur[j1][j2] = maxi; 
                }
            }
            front = cur; 
        }
        return front[0][m - 1];
    }


public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        // return cherryPickupRecursive(0, 0, matrix[0].size()-1, matrix);
        // return cherryPickupMemoization(0, 0, matrix[0].size()-1, matrix, dp);
        // return cherryPickupTabulation(matrix);
        return cherryPickSpaceOptimized(matrix);
    }
};


int main() {
    vector<vector<int>> matrix = {{2,1,3},{4,2,5},{1,6,2},{7,2,8}};
    cout << Solution().cherryPickup(matrix) << endl;
    return 0;
}