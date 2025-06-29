#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> stt;

        for (int i = n - 1; i >= 0; i--) {
            while (!stt.empty() && arr[stt.top()] >= arr[i]) {
                stt.pop();
            }

            ans[i] = stt.empty() ? n : stt.top();
            stt.push(i);
        }
        return ans;
    }

    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> stt;

        for (int i = 0; i < n; i++) {
            while (!stt.empty() && arr[stt.top()] > arr[i])
            {
                stt.pop();
            }

            ans[i] = stt.empty() ? -1 : stt.top();
            stt.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int mod = 1e9 + 7;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int left = (psee[i] == -1) ? (i + 1) : (i - psee[i]);
            int right = (nse[i] == -1) ? (n - i) : (nse[i] - i);

            long long frequency = (left * 1LL * right) % mod;
            int val = (frequency * arr[i]) % mod;
            sum = (sum + val) % mod;
        }

        return sum;
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 4};
    cout << Solution().sumSubarrayMins(arr) << endl;
    return 0;
}