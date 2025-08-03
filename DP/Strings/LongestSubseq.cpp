#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0); 
        int ans = 0; 
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    int val = 1 + prev[j-1]; 
                    cur[j] = val; 
                    ans = max(ans, val); 
                }
                else{
                    cur[j] = 0; 
                }
                
            }
            prev = cur; 
        }
        return ans;
    }
};


int main() {
    string str1 = "abcde", str2 = "abfce";
    cout << Solution().longestCommonSubstr(str1, str2);
    return 0;
}