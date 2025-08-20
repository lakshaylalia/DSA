#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node*> list = vector<Node*>(26, nullptr);
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return list[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        list[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return list[ch - 'a'];
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void decreaseEnd() {
        cntEndWith--;
    }

    void decreasePrefix() {
        cntPrefix--;
    }
    ~Node() {
        for(auto itr : list) {
            if(itr != nullptr) {
                delete itr;
            }
        }
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insertWord(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void eraseWord(string &word) {
        Node* node = root;
        for(char ch : word) {
            if(node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return;
            }
            node -> decreasePrefix();
        }
        node -> decreaseEnd();
    }
    
    ~Trie() {
        delete root;
    }
};

int main() {
    
    return 0;
}