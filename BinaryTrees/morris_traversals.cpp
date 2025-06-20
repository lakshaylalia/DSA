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


vector<int> inorder(TreeNode* root){
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left == NULL){
                ans.push_back(curr -> val);
                curr = curr -> right;
            } else{
                TreeNode* temp = curr -> left;
                while(temp -> right && temp -> right != curr){
                    temp  = temp -> right;
                }
                if(temp -> right == NULL){
                    temp -> right = curr;
                    curr = curr -> left;
                } else{
                    ans.push_back(curr -> val);
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return ans;
}

vector<int> preorder(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* temp = curr->left;
            while (temp->right != NULL && temp->right != curr) {
                temp = temp->right;
            }

            if (temp->right == NULL) {
                temp->right = curr; 
                ans.push_back(curr->val); 
                curr = curr->left;
            } else {
                temp->right = NULL; 
                curr = curr->right;
            }
        }
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
    vector<int> ans = preorder(root);
    for(auto itr : ans) cout << itr << " ";
    return 0;
}