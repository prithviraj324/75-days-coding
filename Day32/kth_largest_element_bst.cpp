#include<bits/stdc++.h>
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
public:
    priority_queue<int> pq;
    void dfs(TreeNode* root, int k) {
        if(!root) return;
        pq.push(root->val);
        if(pq.size() > k) pq.pop();
        if(pq.size() == k && root->val > pq.top()) {
            dfs(root->left, k);
        }
        else {
            dfs(root->left, k);
            dfs(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return pq.top();
    }
};