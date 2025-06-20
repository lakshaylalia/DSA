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

void preorder(TreeNode* root){
    if(!root) return;
    cout << root -> val << " ";
    preorder(root -> left);
    preorder(root -> right);
}

TreeNode* solve(vector<int> preorder, int start, int end){
    if (start > end) return nullptr;
    if (start > preorder.size() - 1) return nullptr;
    if (start == end) {
        return new TreeNode(preorder[start]);
    }
    int rootVal = preorder[start];
    TreeNode* root = new TreeNode(rootVal);
    cout << rootVal << " ";
    int i = start  + 1;
    while(i <= end && preorder[i] < rootVal) i++;
    root -> left = solve(preorder, start+1, i-1);
    root -> right = solve(preorder, i, end);
    return root;
}

TreeNode* bstFromPreorder(vector<int> &preorder){
    return solve(preorder, 0, preorder.size()-1);
}

int main() {
    vector<int> pre = {8,5,1,7,10,12};
    TreeNode* root = bstFromPreorder(pre);
    preorder(root);
    // TreeNode* root = new TreeNode(10);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(15);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(7);
    // root->right->left = new TreeNode(12);
    // root->right->right = new TreeNode(20);
    return 0;
}