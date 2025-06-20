#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int n = Arrival.size();
        int maxCount = 1;
        int cnt = 1;
        int i = 1, j = 0;
        while(i < n && j < n) {
            if(Arrival[i] <= Departure[j])  {
                i++;
                cnt++;
            } else {
                j++;
                cnt--;
            }
            maxCount = max(maxCount, cnt);
        }
        return maxCount;
    }
};

int main() {
    vector<int> Arrival = {900, 1100, 1240};
    vector<int> Departure = {1000, 1200, 1240};
    cout << Solution().findPlatform(Arrival, Departure) << endl;
    return 0;
}
