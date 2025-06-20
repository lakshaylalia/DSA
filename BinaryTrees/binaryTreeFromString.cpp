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

void solve(TreeNode* root, string &ans){
    if(!root) return;
    ans += '(';
    ans += to_string(root -> val);
    if(!root -> left && root -> right){
        ans += '(';
        ans += ')';
    } 
    solve(root -> left, ans);
    solve(root -> right, ans);

    ans += ')';
}

string tree2str(TreeNode* root){
    if(!root) return "";
    string ans = "";
    ans += to_string(root -> val);
    if(!root -> left && root -> right){
        ans += '(';
        ans += ')';
    }
    solve(root -> left, ans);
    solve(root -> right, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    cout << tree2str(root);
    return 0;
}