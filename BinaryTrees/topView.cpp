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

void View(TreeNode* root, int vertical, vector<int> &ans){
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto ptr = q.front();
        q.pop();
        TreeNode* node = ptr.first;
        int vertical = ptr.second;

        if(mpp.find(vertical)== mpp.end()) mpp[vertical] = node -> val;

        if(node -> left != nullptr) q.push({node -> left, vertical - 1});
        if(node -> right != nullptr) q.push({node -> right, vertical + 1});
    }
    for(auto itr : mpp) ans.push_back(itr.second);
}

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr) return ans;
    View(root,0,ans);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(30);
    root -> left -> left = new  TreeNode(40);
    root -> left -> right = new  TreeNode(60);
    root -> right -> left =  new TreeNode(90);
    root -> right -> right =  new TreeNode(100);
    vector<int> result = topView(root);
    for(auto itr : result) cout << itr << " ";
    return 0;
}