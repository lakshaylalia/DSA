#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(auto itr : bills){
            if(itr == 5) fives++;
            else if(itr == 10){
                if(fives > 0){
                    fives--, tens++;
                } else return false;
            } else {
                if(fives > 0 && tens > 0){
                   fives--, tens--;
                } else if(fives >= 3){
                    fives -= 3;
                } else return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5,5,5,10,20};
    cout << Solution().lemonadeChange(bills);
    return 0;
}