#include <bits/stdc++.h>
using namespace std;

    int p = 31, mod = 1000000007;

    bool Rabin_Karp(string txt, string pat) {
        int n = pat.length();
        int m = txt.length();

        long long hashPat = 0, hashText = 0;

        long long pRight = 1, pLeft = 1;

        for (int i = 0; i < n; i++) {
            hashPat += ((pat[i] - 'a' + 1) * pRight) % mod;
            hashText += ((txt[i] - 'a' + 1) * pRight) % mod;
            pRight = (pRight * p) % mod;
        }

        for (int i = 0; i <= m - n; i++) {
            if (hashPat == hashText) {
                if (txt.substr(i, n) == pat)
                    return true;
            }

            hashText =  (hashText - ((txt[i] - 'a' + 1) * pLeft) % mod + mod) % mod;
            hashText = (hashText + ((txt[i + n] - 'a' + 1) * pRight) % mod) % mod;
            hashPat = (hashPat * p) % mod;
            pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;
        }

        return false;
    }

int solve(string &a, string &b, int n, int m) {
        if (a == b)
            return 0;
        if (a == "" || b == "")
            return -1;

        int count = 0;
        string src = a;

        while (src.size() < b.size()) {
            src += src;
            count++;
        }

        if (src == b) {
            return count;
        }   
        if (Rabin_Karp(src, b)) {
            return count;
        }         
        if (Rabin_Karp(src + a, b)) {
            return count + 1;
        }
        return -1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            x.push_back(c);
        }
        for(int i = 0; i < m; i++) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        cout << solve(x, s, n, m) << endl;
    }
    return 0;
}