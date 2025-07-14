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

TreeNode* leastCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    if(p -> val < root -> val && q -> val < root -> val) return leastCommonAncestor(root -> left, p, q);
    else if(p -> val > root -> val && q -> val > root -> val) return leastCommonAncestor(root -> right, p, q);
    return root;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
        
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    cout << leastCommonAncestor(root, root->left->left, root->right->right)->val << endl;
    return 0;
}