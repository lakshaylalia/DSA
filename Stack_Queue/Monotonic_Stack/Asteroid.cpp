#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> stt;
        for(auto itr : asteroids) {
            if(itr > 0) {
                stt.push(itr);
            } else {
                int val = abs(itr);
                while(!stt.empty() && stt.top() < val) {
                    stt.pop();
                }

                if(!stt.empty() && stt.top() == val) {
                    stt.pop();
                    continue;
                }

                if(stt.empty()) {
                    ans.push_back(itr);
                }
            }
        }
        vector<int> temp;
        while(!stt.empty()) {
            temp.push_back(stt.top());
            stt.pop();
        }
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};

int main() {
    vector<int> asteroids = {10, 2, -5, -10, -20};
    vector<int> ans = Solution().asteroidCollision(asteroids);
    for(auto itr : ans) {
        cout << itr << " ";
    }
    return 0;
}