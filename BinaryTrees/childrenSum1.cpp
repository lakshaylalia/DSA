#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;

    TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) {
        val = x;
        left = l;
        right = r;
    }
};

int value(TreeNode* root){
    if(root == nullptr) return 0;
    return root -> val;
}

bool check(TreeNode* root){
    if(!root) return true;
    if(root -> left == nullptr && root -> right == nullptr) return true;
    if(value(root -> left) + value(root -> right) != root -> val) return false;
    return (check(root -> left) && check(root -> right));
}

int isSumProperty(TreeNode* root){
    return check(root);
}

int main() {
    
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(10);
    root -> right = new TreeNode(3);
    root -> left -> left = new TreeNode(5);
    root -> left -> right = new TreeNode(5);
    root -> right -> left = new TreeNode(10);
    root -> right -> right = new TreeNode(5);
    cout << isSumProperty(root);
    return 0;
}