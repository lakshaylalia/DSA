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


int widthOfTree(TreeNode* root){
    if(!root) return 0;

    queue<pair<TreeNode*, int>> q;
    long long ans = 0;
    q.push({root, 0});
    while(!q.empty()){
    long long size = q.size();
        long long mmin = q.front().second;
        long long first, last;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front().first;
            long long curr_idx = q.front().second - mmin;
            q.pop();
            if(i == 0) first = curr_idx;
            if(i == size - 1) last = curr_idx;

            if(node -> left) q.push({node -> left, curr_idx * 2 + 1});
            if(node -> right) q.push({node -> left, curr_idx * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << widthOfTree(root) << endl;
    return 0;
}