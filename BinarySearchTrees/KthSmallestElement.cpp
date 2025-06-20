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

void findElement(TreeNode* root, int k, int &el){
    if(!root) return;
    findElement(root -> left, k, el);
    k--;
    if(k == 0){
        el = root -> val;
        return;
    }
    findElement(root -> right, k, el);

}

int kthSmallest(TreeNode* root, int k) {
    int el = -1;
    findElement(root, k, el);
    return el;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    cout << kthSmallest(root, 3) << endl;
    return 0;
}