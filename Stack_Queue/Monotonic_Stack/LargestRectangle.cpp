#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stt;
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            while(!stt.empty() && heights[stt.top()] > heights[i]) {
                int elIdx = stt.top();
                stt.pop();
                int el = heights[elIdx];
                int nse = i;
                int pse = stt.empty() ? -1 : stt.top();
                maxArea = max(maxArea, el*(nse-pse-1));
            }
            stt.push(i);
        }
        while(!stt.empty()) {
            int el = heights[stt.top()];
            stt.pop();
            int nse = n;
            int pse = stt.empty() ? -1 : stt.top();
            maxArea = max(maxArea, el*(nse-pse-1));
        }
        return maxArea;
    }
};


// class Solution {
// private:
//     vector<int> findNSE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> ans(n, n);
//         stack<int> stt;
//         for(int i = n-1; i >= 0; i--) {
//             while(!stt.empty() && heights[stt.top()] >= heights[i]) {
//                 stt.pop();
//             }
//             if(!stt.empty()) {
//                 ans[i] = stt.top();
//             }
//             stt.push(i);
//         }
//         return ans;
//     }

//     vector<int> findPSEE(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> ans(n, -1);
//         stack<int> stt;
//         for(int i = 0; i < n; i++) {
//             while(!stt.empty() && heights[stt.top()] > heights[i]) {
//                 stt.pop();
//             }
//             if(!stt.empty()) {
//                 ans[i] = stt.top();
//             }
//             stt.push(i);
//         }
//         return ans;
//     }
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         vector<int> nse = findNSE(heights);
//         vector<int> pse = findPSEE(heights);
//         int maxArea = 0;
//         for(int i = 0; i < n; i++) {
//             int height = max(nse[i], pse[i]);
//             int width = nse[i] - pse[i] - 1;
//             int area = heights[i] * width;
//             maxArea = max(maxArea, area);
//         }
//         return maxArea;
//     }
// };

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(heights) << endl;
    return 0;
}