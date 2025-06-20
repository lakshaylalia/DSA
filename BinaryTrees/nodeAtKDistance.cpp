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


void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
    queue<TreeNode*> q;
    q.push(root); 

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node->left) {
            q.push(node->left);
            parent_track[node->left] = node;
        }
        if (node->right) {
            q.push(node->right);
            parent_track[node->right] = node;
        }
    }
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!root) return {};

    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track);  

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    
    q.push(target);
    visited[target] = true;

    int curr_dist = 0;

    while (!q.empty()) {
        if (curr_dist == k) break;
        curr_dist++;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            
            if (node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }
            
            if (node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }

            if (parent_track.count(node) && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}


int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(14);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(2);
    root->left->left->left = new TreeNode(15);
    root->left->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(12);
    root->left->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(8);
    root->right->left->right = new TreeNode(5);
    root->left->right->left->left = new TreeNode(100);
    root->left->right->left->right = new TreeNode(62);
    root->left->right->left->left->left = new TreeNode(64);

    TreeNode* target = root->left->right; 
    vector<int> res = distanceK(root, target, 2);
    for(auto itr : res) cout << itr <<" ";

    return 0;
}