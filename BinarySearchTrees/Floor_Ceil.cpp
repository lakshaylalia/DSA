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

int floor(TreeNode* root, int x){
    if(!root) return -1;
    TreeNode* temp = root;
    int floor = -1;
    while(temp){
        if(temp -> val == x) return x;
        else if(temp -> val > x) temp = temp -> left;
        else{
            floor = temp -> val;
            temp = temp -> right;
        }
    }
    return floor;
}

int ceil(TreeNode* root, int x){
    if(!root) return -1;
    TreeNode* temp = root;
    int ceil = -1;
    while(temp){
        if(temp -> val == x) return x;
        else if(temp -> val > x){
            ceil = temp -> val;
            temp = temp -> left;
        }
        else temp = temp -> right;
    }
    return ceil;
}

int main() {
    TreeNode* root = new TreeNode(11);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    cout << "Floor of 10 is " << floor(root, 10) << endl;
    cout << "Ceil of 10 is " << ceil(root, 10) << endl;

    return 0;
}