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

bool path(TreeNode* root, int x, vector<int>&ans){
    if(!root) return false;

    ans.push_back(root -> val);

    if(root -> val == x) return true;
    if(path(root -> left, x, ans) || path(root -> right, x, ans)) return true;
    ans.pop_back();
    return false;
}

vector<int> rootToNode(TreeNode* root, int x){
    vector<int> ans;
    if(!root) ans;
    bool res = path(root, x, ans);
    if(!res) return {}; // if node not found
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

    int x = 70;
    vector<int> ans = rootToNode(root, x);
    for(auto itr : ans) cout << itr << " ";

    return 0;
}