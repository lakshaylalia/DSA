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

void solve(TreeNode* root, int &pred, int &succ, int key){
    if(!root) return;
    if(root -> val < key){
        pred = root -> val;
        solve(root -> right, pred, succ, key);
    }
    else if(root -> val > key) {
        succ = root -> val;
        solve(root -> left, pred, succ, key);
    }
    return;
}

vector<int> succPredBST(TreeNode* root, int key){
    if(!root) return {-1, -1};
    if(root -> val == key){
        if(root -> left && root -> right) return {root -> left -> val, root -> right -> val};
        else if(!root -> left) return {-1, root -> right -> val};
        else return {root -> left -> val, -1};
    }
    int pred = -1;
    int succ = -1;
    solve(root, pred, succ, key);
    return {pred, succ};
}
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root -> left -> left -> left = new TreeNode(1);
    root -> right -> right -> left = new TreeNode(8);
    root -> right -> right -> right = new TreeNode(10);
    vector<int> ans = succPredBST(root, 5);
    cout << ans[0] << " " << ans[1];
    return 0;
}