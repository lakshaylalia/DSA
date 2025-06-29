#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int r = n-1;
        int leftSum = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;

        for(int i = k-1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            rightSum += cardPoints[r];
            maxSum = max(maxSum, leftSum+rightSum);
            r--;
        }
        return maxSum;
    }
};
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int totalSum = 0;
//         for(auto itr : cardPoints) {
//             totalSum += itr;
//         }

//         if (k == n) return totalSum;

//         int windowSize = n - k;
//         int windowSum = 0;

       
//         for (int i = 0; i < windowSize; i++) {
//             windowSum += cardPoints[i];
//         }

//         int minWindowSum = windowSum;

//         for (int i = windowSize; i < n; i++) {
//             windowSum += cardPoints[i] - cardPoints[i - windowSize];
//             minWindowSum = min(minWindowSum, windowSum);
//         }

//         return totalSum - minWindowSum;
//     }
// };


int main() {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    cout << Solution().maxScore(cardPoints, 3) << endl;
    return 0;
}