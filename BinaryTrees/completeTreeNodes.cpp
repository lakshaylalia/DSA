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

int Height(TreeNode* root) {
        int level = 0;
        while (!root) {
            level++;
            root = root->left;
        }
        return level;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int nodes = 0;
    int height = Height(root);
    int curr_level = 0;
    while (!q.empty()) {
        bool flag = true;
        int size = q.size();
        nodes += size;
        nodes += size;
        curr_level++;
        if (curr_level == height - 1) {
            flag = false;
        }
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            if (flag) {
                q.pop();
                if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                } else {
                    if (node->right) {
                        nodes += 2;
                        q.pop();
                    } else if (node->left) {
                        nodes += 1;
                        return nodes;
                    } else{
                        return nodes;
                    }
                }
            }
        }
    return nodes;
}

int main() {
    TreeNode* root = new TreeNode(1);
    cout << countNodes(root) << endl;
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(6);
    // root->right->right = new TreeNode(7);
    return 0;
}