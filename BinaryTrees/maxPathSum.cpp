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

int sum(TreeNode* root, int &maxi){
    if(!root) return 0;

    int ls = max(0, sum(root -> left, maxi));
    int rs = max(0, sum(root -> right, maxi));
    maxi = max(maxi, root -> val + ls + rs);
    return root -> val + max(ls, rs);
}

int maxPathSum(TreeNode* root){
    if(!root) return 0;
    int maxi = INT_MIN;
    sum(root, maxi);
    return maxi;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    cout << maxPathSum(root) << endl;
    return 0;
}