#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1, lMax = 0, rMax = 0, total = 0;
        while(l < r) {
            if(height[l] <= height[r]) {
                if(lMax > height[l]) {
                    total += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                
                if(rMax > height[r]) {
                    total += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         vector<int> leftMax(n, 0);
//         vector<int> rightMax(n, 0);
//         leftMax[0] = height[0];
//         for (int i = 1; i < n; i++) {
//             leftMax[i] = max(leftMax[i - 1], height[i]);
//         }

//         rightMax[n - 1] = height[n - 1];
//         for (int i = n - 2; i >= 0; i--) {
//             rightMax[i] = max(rightMax[i + 1], height[i]);
//         }

//         int total = 0;
//         for (int i = 0; i < n; i++) {
//             int water = min(leftMax[i], rightMax[i]) - height[i];
//             if (water > 0)
//                 total += water;
//         }
//         return total;
//     }
// };

int main() {
    vector<int> height = {4,2,0,3,2,5};
    cout << Solution().trap(height);
    return 0;
}