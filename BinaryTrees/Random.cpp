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

bool hasPathSum(TreeNode* root, int targetSum){
    if(root == nullptr) return false;
    if(root -> left == nullptr && root -> right == nullptr) {
        if(targetSum == root -> val) return true;
        return false;
    }
    return(hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
}


void path(TreeNode* root, int targetSum, vector<int> &ds, vector<vector<int>> &ans){
    if(!root) return;
    if(root -> left == nullptr && root -> right == nullptr){
        if(targetSum - root -> val == 0) {
            ds.push_back(root -> val);
            ans.push_back(ds);
            ds.pop_back();
        }
        return;
    }
    ds.push_back(root -> val);
    path(root -> left, targetSum - root -> val, ds, ans);
    path(root -> right, targetSum - root -> val, ds, ans);
    ds.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<vector<int>> ans; 
    if(!root) return ans;
    vector<int> ds;
    path(root, targetSum, ds, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> right = new TreeNode(3);
    root -> left->left = new TreeNode(4);
    root-> left->right = new TreeNode(5);
    root -> right->left = new TreeNode(6);
    root -> right->right = new TreeNode(7);
     
    vector<vector<int>> ans = pathSum(root, 11);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}