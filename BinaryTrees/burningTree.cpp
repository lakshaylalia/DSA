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

TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int target) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res = nullptr;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr -> val == target) res = curr;

        if(curr -> left){
            parent_track[curr -> left] = curr;
            q.push(curr -> left);
        }
        if(curr -> right){
           parent_track[curr -> right] = curr;
           q.push(curr -> right);
        }
            
    }
    return res;
}



void recurssive(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, unordered_map<TreeNode*, bool>& visited, int& time) {
    if (!root || visited[root]) return;  // Base case: if the node is null or already visited

    visited[root] = true;

    
    if (root->left && !visited[root->left]) {
        recurssive(root->left, parent_track, visited, time);
    }

   
    if (root->right && !visited[root->right]) {
        recurssive(root->right, parent_track, visited, time);
    }

 
    if (parent_track.find(root) != parent_track.end() && !visited[parent_track[root]]) {
        recurssive(parent_track[root], parent_track, visited, time);
    }

    time++;
}


int minTime(TreeNode* root, int target){
    if(!root) return 0;
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track, target);
    unordered_map<TreeNode*, bool> visited;
    TreeNode* p = markParents(root, parent_track, target);
    int time = 0;
    // recurssive(p, parent_track, visited, time);
    visited[p] = true;
    queue<TreeNode*> q;
    q.push(p);
    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i = 0; i < size; i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr -> left && !visited[curr -> left]){
                flag = 1;
                q.push(curr -> left);
                visited[curr -> left] = true;
            }
            if(curr -> right && !visited[curr -> right]){
                flag = 1;
                q.push(curr -> right);
                visited[curr -> right] = true;
            }
            if(parent_track.find(curr) != parent_track.end() && !visited[parent_track[curr]]){
                flag = 1;
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
            }
        }
        if(flag) time++;
    }
    return time;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right -> left = new TreeNode(7);
    root->left->right -> right= new TreeNode(8);
    root->right->right = new TreeNode(6);
    root->right->right -> right = new TreeNode(9);
    root->right->right -> right -> right = new TreeNode(10);
    cout << minTime(root, 8) << endl;
    return 0;
}