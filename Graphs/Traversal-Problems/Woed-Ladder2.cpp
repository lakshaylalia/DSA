#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> stt(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        stt.erase(beginWord);
        q.push({beginWord});
        vector<vector<string>> ans;
        unordered_set<string> toErase;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                vector<string> seq = q.front();
                q.pop();
                string word = seq.back();

                if (word == endWord) {
                    if (ans.empty()) {
                        ans.push_back(seq);
                    } else if (ans[0].size() == seq.size()) {
                        ans.push_back(seq);
                    }
                }

                for (int i = 0; i < word.size(); i++) {
                    char orignal = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if (stt.find(word) != stt.end()) {
                            seq.push_back(word);
                            q.push(seq);
                            toErase.insert(word);
                            seq.pop_back();
                        }
                    }
                    word[i] = orignal;
                }
            }
            for (auto itr : toErase) stt.erase(itr);
            toErase.clear();
            if (!ans.empty()) break;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}