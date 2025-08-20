#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<Node*> list = vector<Node*>(26, nullptr);
    bool flag = false;

    bool containsKey(char ch) {
        return list[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        list[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return list[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    // destructor
    ~Node() {
        for(int i = 0; i < 26; i++) {
            if(list[i] != nullptr) {
                delete list[i];
            }
        }
    }
};

class Trie{
private:
   Node* root;
public:
    Trie(){
        root = new Node();
    }

    ~Trie() {
        delete root;
    }

    void insert(string word) {
           Node* node = root;
           for(char ch : word) {
            if(!node -> containsKey(ch)) {
                node -> put(ch, new Node());
            }
            node = node -> get(ch);
           }
           node -> setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for(char ch : word) {
            if(node -> containsKey(ch)) {
                node = node -> get(ch);
            } else {
                return false;
            }
        }
        return node -> isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch : prefix) {
            if(node -> containsKey(ch)) {
                node = node -> get(ch);
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}