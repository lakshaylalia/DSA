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

vector<int> bottomView(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;

    map<int, int> mpp;
    queue<pair<TreeNode*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int vertical = p.second;
        mpp[vertical] = node -> val;
        if(node -> left != nullptr) q.push({node -> left, vertical - 1});
        if(node -> right != nullptr) q.push({node -> right, vertical + 1});
    }
    for(auto itr : mpp) ans.push_back(itr.second);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);
    root->right->left = new TreeNode(90);
    root->right->right = new TreeNode(100);

    vector<int> res = bottomView(root);
    for(auto itr : res) cout << itr <<" ";
    
    return 0;
}