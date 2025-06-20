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



void rightView(TreeNode* root, int level, vector<int>&ans){
    if(!root) return;

    if(level == ans.size()) ans.push_back(root -> val);
    rightView(root -> right, level + 1, ans);
    rightView(root -> left, level + 1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
     
    // Recurssive 
    // rightView(root, 0 , ans);


    // Level Order Traversal
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> ds;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();

            ds.push_back(node -> val);
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        ans.push_back(ds[ds.size() - 1]);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);
    root->right->left = new TreeNode(70);
    root->right->right = new TreeNode(80);
    vector<int> res = rightSideView(root);
    for(auto itr : res){
        cout << itr <<" ";
    }
    return 0;
}