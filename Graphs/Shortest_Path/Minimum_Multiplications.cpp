#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumMultiplications(vector<int> &arr,int start, int end) {
        queue<pair<int ,int>> q;
        vector<int> steps(100000, 1e9);
        q.push({start, 0});
        while(!q.empty()) {
            auto [num, step] = q.front();
            q.pop();
            if(num == end) return step;
            for(auto itr : arr) {
                int newNum = (num * itr) % 100000;
                if(step + 1 < steps[newNum]) {
                    steps[newNum] = step + 1;
                    q.push({newNum, step + 1});
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<int> arr = {2, 5, 7};
    cout << Solution().minimumMultiplications(arr, 3, 30) << endl;
    return 0;
}