#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    // vector<int> computeLPS(string s) {
    //     int n = s.size();       
    //     vector<int> LPS(n, 0);

    //     for(int i=1; i < n; i++) {
    //         for(int len = 1; len < i; len++) {
    //             if(s.substr(0, len) == s.substr(i-len+1, len)) {
    //                 LPS[i] = len;
    //             }      
    //         }
    //     }
        
    //     return LPS;
    // } 
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);  
        int i = 1, j = 0;

        while(i < n) {
            if(s[i] == s[j]) {
                LPS[i] = j+1;
                i++, j++;
            } else {
                while(j > 0 && s[i] != s[j]) {
                    j = LPS[j-1];
                }
                if(s[i] == s[j]) {
                    LPS[i] = j+1;
                    j++;
                }
                i++;
            }
        }
        
        return LPS;
    }
    
public:
    vector<int> search(string pattern, string text)   {
        string s = pattern + '$' + text; 
        vector<int> LPS = computeLPS(s);
        int n = text.size(), m = pattern.size();

        vector<int> ans;

        for(int i = m+1; i < s.size(); i++) {
            if(LPS[i] == m) ans.push_back(i - 2*m);
        }
        
        return ans;
    }
};

int main() {
    string txt = "abracadabra";
    string pattern = "abra";
    vector<int> ans = Solution().search(pattern, txt);
    for(auto itr : ans) {
        cout << itr << " ";
    }
    return 0;
}