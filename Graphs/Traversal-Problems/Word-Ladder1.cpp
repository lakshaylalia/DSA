#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> stt(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        stt.erase(beginWord);

        while(!q.empty()){
            auto [word, steps] = q.front();
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                char orignal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(stt.find(word) != stt.end()){
                        stt.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = orignal;
            }
        }
        return 0;
    }
};

int main() {
    
    return 0;
}