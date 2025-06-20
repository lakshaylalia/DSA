#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val, Node* left = nullptr, Node* right = nullptr){
        this -> val = val;
        this -> left = left;
        this -> right = right;
    }
};


void preOrder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    stack<Node*> stt;
    Node* ptr = root;
    while(ptr != NULL){
        ans.push_back(ptr -> val);
        if(ptr -> right != NULL){
            stt.push(ptr -> right);
        }
        if(ptr -> left != NULL) ptr = ptr -> left;
        else{
            if(stt.empty()) break;
            else{
                ptr = stt.top();
                stt.pop();
            }
        }
    }
}


void inOrder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    stack<Node*> stt;
    Node* ptr = root;
    while(true){
        if(ptr != NULL){
            stt.push(ptr);
            ptr = ptr -> left;
        } else{
            if(stt.empty()) break;
            ptr = stt.top();
            stt.pop();
            ans.push_back(ptr -> val);
            ptr = ptr -> right;
        }
    }
}

int main() {
    Node* root1 = new Node(1);
    if(root1 -> left) cout << "Hello";
    else cout << "Hehe";
    // root1->left = new Node(2);
    // root1->right = new Node(3);
    // Node* root2 = new Node(1);
    // root2->left = new Node(2);
    // root2->right = new Node(3);
    // vector<int> ans;
    // inOrder(root1, ans);
    // for(auto i : ans) cout << i << " ";
    return 0;
}
