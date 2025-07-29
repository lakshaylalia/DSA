#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<long long, long long> getHash(string text, string pattern, int mod, int p) {
        long long hash_txt = 0;
        long long hash_pat = 0;
        long long m = pattern.size();
        long long pow = 1;   
    
        for (int i = m - 1; i >= 0; i--) {
           hash_txt = (hash_txt + 1LL * (text[i] - 'a' + 1) * pow % mod) % mod;
           hash_pat = (hash_pat + 1LL * (pattern[i] - 'a' + 1) * pow % mod) % mod;
           pow = (1LL * pow * p) % mod;
       }

        return make_pair(hash_txt, hash_pat);
    }

public:

    vector<int> RabinKarp(string txt, string pat) {
        int n = txt.size(), m = pat.size();
        if(m > n || txt == "" || pat == "") {
            return {};
        }
        if(txt == pat) {
            return {0};
        }

        vector<int> ans;
        int p1 = 29, mod1 = 1000000007;
        int p2 = 31, mod2 = 1000000009;
        auto [txtHash, patHash] = getHash(txt, pat, mod1, p1);
        auto [txtHash2, patHash2] = getHash(txt, pat, mod2, p2);

        if(txtHash == patHash && txtHash2 == patHash2) {
            ans.push_back(0);
        }
        long long pow1 = 1, pow2 = 1;
        for(int i = 1; i < m ; i++) {
            pow1 = (1LL * pow1 * p1) % mod1;
            pow2 = (1LL * pow2 * p2) % mod2;
        }

        for(int i = 1; i <= n-m; i++) {
            int out_char = txt[i-1]-'a'+1;
            int in_char = txt[i+m-1]-'a'+1;

            txtHash = (txtHash - (out_char*pow1)%mod1 + mod1) % mod1;
            txtHash = (txtHash * p1) % mod1;
            txtHash = (txtHash + in_char) % mod1;

            txtHash2 = (txtHash2 -(out_char*pow2)%mod2 + mod2) % mod2;
            txtHash2 = (txtHash2 * p2) % mod2;
            txtHash2 = (txtHash2 + in_char) % mod2;

            if(txtHash == patHash && txtHash2 == patHash2) {
                ans.push_back(i);
            }
        }
        return ans;
    }


    // vector<int> search(string pat, string txt) {
    //     int n = pat.length();
    //     int m = txt.length();
        
    //     int p = 29, mod = 101;
        
    //     // To store the hash values of pattern and susbtring of text
    //     int hashPat = 0, hashText = 0;
        
    //     int pRight = 1, pLeft = 1;
        
    //     // Computing the initial hash values
    //     for(int i=0; i < n; i++) {
    //         hashPat += ((pat[i]-'a'+1) * pRight) % mod;
    //         hashText += ((txt[i]-'a'+1) * pRight) % mod;
    //         pRight = (pRight * p) % mod;
    //     }
        
    //     // List to store the result
    //     vector<int> ans;
        
    //     // Traverse the text string
    //     for(int i=0; i <= m-n; i++) {
            
    //         // If the hash value matches
    //         if(hashPat == hashText) {
    //             // Add the index of the result if the substring matches
    //             if(txt.substr(i, n) == pat) ans.push_back(i);
    //         }
            
    //         // Updating the hash values
    //         hashText = (hashText - ((txt[i] - 'a'+1) * pLeft) % mod + mod) % mod;
    //         hashText = (hashText + ((txt[i+n] - 'a'+1) * pRight) % mod) % mod;
    //         hashPat = (hashPat * p) % mod;
            
    //         // Updating the prime multiples
    //         pLeft = (pLeft * p) % mod;
    //         pRight = (pRight * p) % mod;
    //     }
    //     return ans; // Return the stored result
    // } 

};

int main() {
    string pat = "abc";
    string txt = "ababcabcababc";
    vector<int> ans = Solution().RabinKarp(txt, pat);
    for(auto itr : ans) {
        cout << itr << " ";
    }
    return 0;
}