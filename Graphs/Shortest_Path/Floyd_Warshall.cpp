#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) {
                    matrix [i][j] = 1e9;
                }
                if(i == j) {
                    matrix[i][j] = 0;
                }
            }
        }
 
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1e9) {
                    matrix [i][j] = -1;
                }
            }
        }
	}
};

int main() {

    vector<vector<int>> matrix = {{0, 1, 2, -1}, {1, 0, 3, 4}, {2, 3, 0, 5}, {-1, 4, 5, 0}};
    Solution().shortestDistance(matrix);
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix.size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}