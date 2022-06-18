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
//path to node must be strictly non-decreasing to consider node as good node
class Solution {
public:
    int dfs(TreeNode* root, int parentval) {
        if(!root) return 0;
        if(root->val >= parentval)
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        else 
            return dfs(root->left, parentval) + dfs(root->right, parentval);
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};