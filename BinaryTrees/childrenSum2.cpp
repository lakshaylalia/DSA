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

void childSum2(TreeNode* root){
    if(!root) return;

    int child = 0;
    if(root -> left) child += root->left->val;
    if(root->right) child += root->right->val;

    if(root -> val <= child) root->val = child;
    else{
        if(root -> left) root->left->val = root->val;
        if(root -> right) root->right->val = root->val;
    }

    childSum2(root->left);
    childSum2(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root -> left || root -> right) root->val = total;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans;
    childSum2(root);
    return 0;
}