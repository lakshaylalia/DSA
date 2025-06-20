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

TreeNode* findLastNode(TreeNode* root){
    if(!root -> right) return root;
    findLastNode(root -> right);
}

TreeNode* helper(TreeNode* root){
    if(!root -> left) return root -> right;
    else if(!root -> right) return root -> left;
    TreeNode* rightChild = root -> left;
    TreeNode* rightMost = findLastNode(root -> right);
    rightMost -> right = rightChild;
    return root -> left;
}

TreeNode* deleteNode(TreeNode* root, int key){
    if(!root) return root;
    if(root -> val == key) return helper(root);

    TreeNode* temp = root;
    while(temp){
        if(temp -> val > key){
            if(temp -> left && temp -> left -> val == key){
                temp -> left = helper(temp -> left);
                break;
            } else temp = temp -> left;
        } else{
            if(temp -> right && temp -> right -> val == key){
                temp -> right = helper(temp -> right);
                break;
            } else temp = temp -> right;
        }
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    return 0;
}