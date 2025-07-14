#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
int robRecursive(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }

    int take = root->val;
    if(root->left) {
        take += robRecursive(root->left->left);
        take += robRecursive(root->left->right);
    }
    if(root->right) {
        take += robRecursive(root->right->left);
        take += robRecursive(root->right->right);
    }

    int notTake = robRecursive(root->left) + robRecursive(root->right);

    return max(take, notTake);
}

int robMemoization(TreeNode* root, unordered_map<TreeNode*,int> &dp) {
    if(root == NULL) {
        return 0;
    }

    if(dp.find(root) != dp.end()) {
        return dp[root];
    }

    int take = root->val;
    if(root -> left) {
        take += robMemoization(root->left->left, dp);
        take += robMemoization(root->left->right, dp);
    }
    if(root -> right) {
        take += robMemoization(root->right->left, dp);
        take += robMemoization(root->right->right, dp);
    }

    int notTake = robMemoization(root->left, dp) + robMemoization(root->right, dp);
    return dp[root] = max(take, notTake);
}


public:
    int rob(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        // return robRecursive(root);
        unordered_map<TreeNode*, int> dp;
        return robMemoization(root, dp);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    // root->right->right = new TreeNode(1);
    cout << Solution().rob(root) << endl;
    return 0;
}