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

bool isLeaf(TreeNode* root){
    return !root -> left && !root -> right;
}

void rootToLeaf(TreeNode* root, vector<int>&path, vector<vector<int>>&ans){
    if(!root) return;

    path.push_back(root->val);

    if(isLeaf(root)){
        ans.push_back(path);
    } else{
        rootToLeaf(root->left, path, ans);
        rootToLeaf(root->right, path, ans);
    }

    path.pop_back();
}

vector<vector<int>> Paths(TreeNode* root){
    vector<vector<int>> ans;
    if(!root) return ans;
    vector<int> path;
    rootToLeaf(root, path, ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(70);
    vector<vector<int>> ans = Paths(root);
    for(auto i: ans){
        for(auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}