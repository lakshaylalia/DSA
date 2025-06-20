#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left, *right;

    TreeNode(int x = 0, TreeNode* l = nullptr, TreeNode* r = nullptr){
        val = x;
        left = l;
        right = r;
    }
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return nullptr;
    if(root == nullptr || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root -> left, p, q);
    TreeNode* right = lowestCommonAncestor(root -> right, p, q);
    if(left && right) return root;
    if(left) return left;
    return right;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);
    TreeNode* lca = lowestCommonAncestor(root, root->left, root->right);
    cout << lca -> val;
    return 0;
}