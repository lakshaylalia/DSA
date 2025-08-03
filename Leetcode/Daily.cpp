#include <bits/stdc++.h>
using namespace std;


int solve(int A, int B, int C) {
    if (A == 0) {
        return 0;
    }

    vector<long long> cells(A + 1, 0);
    cells[1] = 1;
    int MOD = 1000000007;
    for (int day = 2; day <= A; ++day) {
        if (day <= C) {
            cells[day] = (cells[day - 1] * 2) % MOD;
        } else {
            int effective_day = (day - 1) % C + 1;
            if (effective_day == 1) {
                cells[day] = 1;
            } else if (effective_day <= B) {
                cells[day] = (cells[day - 1] * 2) % MOD;
            } else {
                cells[day] = 1;
            }
        }
    }
    return (int)cells[A];
}

vector<int> Solve(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> bookCount;
    multiset<int> countTracker;
    vector<int> maxValues;

    for (size_t idx = 0; idx < A.size(); ++idx) {
        int currentId = A[idx];
        int delta = B[idx];
        auto it = bookCount.find(currentId);
        int oldCount = (it != bookCount.end()) ? it->second : 0;
        if (oldCount > 0) {
            auto pos = countTracker.find(oldCount);
            if (pos != countTracker.end()) {
                countTracker.erase(pos);
            }
        }
        int newCount = oldCount + delta;
        bookCount[currentId] = newCount;
        if (newCount > 0) {
            countTracker.insert(newCount);
        }

        int currentMax = countTracker.empty() ? 0 : *countTracker.rbegin();
        maxValues.push_back(currentMax);
    }

    return maxValues;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int A, B, C;
        // Input values
        cin >> A >> B >> C;
        cout << solve(A, B, C) << endl;
    }
    // vector<int> A = {2, 3, 2, 1};
    // vector<int >B = {3, 2 -3, 1};
    // vector<int> ans =  Solve(A, B);
    // for(auto itr : ans) {
    //     cout << itr << " ";
    // }
    return 0;
}