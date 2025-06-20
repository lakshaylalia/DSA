#include<bits/stdc++.h>
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

TreeNode* search(TreeNode* root, int x){
    if(!root) return NULL;
    if(root -> val == x) return root;
    else if(root -> val > x) return search(root -> left, x);
    return search(root -> right, x);
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root -> left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    TreeNode* x = search(root, 15);
    if(x) cout << x -> val << endl;
    else cout << "Not found" << endl;
    return 0;
}
