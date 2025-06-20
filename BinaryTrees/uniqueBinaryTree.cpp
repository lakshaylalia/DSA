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

void traversal(TreeNode* root){
    if(!root) return;
    cout << root -> val << " ";
    traversal(root -> left);
    traversal(root -> right);
}

TreeNode* buildtree(vector<int>& inorder, int inStart, int inEnd, vector<int>& preorder, int preStart, int preEnd, unordered_map<int, int> &mpp){
    if(preStart > preEnd || inStart > inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int rootIdx = mpp[preorder[preStart]];
    int leftElements = rootIdx - inStart;
    root -> left = buildtree(inorder, inStart, rootIdx - 1, preorder, preStart + 1, preStart + leftElements, mpp);
    root -> right = buildtree(inorder, rootIdx + 1, inEnd, preorder, preStart + leftElements + 1, preEnd, mpp);
    return root;
}

TreeNode* buildTree1(vector<int>& inorder, vector<int>& preorder){
    unordered_map<int, int> mpp;
    for(int i = 0 ; i < inorder.size(); i++) mpp[inorder[i]] = i;
    return buildtree(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1, mpp);
    
}

TreeNode* buildtree2(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& mpp) {
    if (inStart > inEnd || postStart > postEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int rootIdx = mpp[postorder[postEnd]];
    int leftElements = rootIdx - inStart;

    root->left = buildtree2(inorder, inStart, rootIdx - 1, postorder, postStart, postStart + leftElements - 1, mpp);
    root->right = buildtree2(inorder, rootIdx + 1, inEnd, postorder, postStart + leftElements, postEnd - 1, mpp);

    return root;
}

TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); i++) mpp[inorder[i]] = i;
    return buildtree2(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
}

int main() {
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10 ,20, 40, 50, 30, 60};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    TreeNode * root = buildTree2(inorder, postorder);
    traversal(root);
    return 0;
}