#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stt;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        if(!stt.empty() && stt.top().first > price) {
            stt.push({price, 1});
            return 1; 
        } else {
            while(!stt.empty() && stt.top().first <= price) {
                auto var = stt.top();
                ans += var.second;
                stt.pop();
            }
            stt.push({price, ans});
        }
        return ans;
    }
};


// class Solution {
// private:
//     vector<int> findPGE(vector<int> arr) {
//         int n = arr.size(); //size of array
//         vector<int> ans(n);  
//         stack<int> st;
        
//         for(int i=0; i < n; i++) {
//             int currEle = arr[i];
//             while(!st.empty() && arr[st.top()] <= currEle) {
//                 st.pop();
//             }
//             if(st.empty()) 
//                 ans[i] = -1;
//             else 
//                 ans[i] = st.top();
//             st.push(i);
//         }
//         return ans;
//     }
    
// public:
//     vector <int> stockSpan(vector<int> arr, int n) {
//         vector<int> PGE = findPGE(arr);
//         vector<int> ans(n);

//         for(int i=0; i < n; i++) {
//             ans[i] = i - PGE[i];
//         }
//         return ans;
//     }
// };

// int main() {
//     int n = 7;
//     vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
//     vector<int> ans = sol.stockSpan(arr, n);
//     cout << "The span of stock prices is: ";
//     for(int i=0; i < n; i++) {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }
