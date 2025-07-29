#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Sentinel
        int maxArea = 0, n = heights.size();
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int h = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    int findMaxRectangle(vector<vector<int>> &heights) {
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(heights[i]));
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            heights[0][j] = matrix[0][j] - '0';
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    heights[i][j] = heights[i-1][j] + 1;
                }
            }
        }
        return findMaxRectangle(heights);
    }
};


int main() {
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout << Solution().maximalRectangle(matrix);
    return 0;
}