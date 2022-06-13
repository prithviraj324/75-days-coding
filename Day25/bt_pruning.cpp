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
    bool prune(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right && root->val==0) return true;// true means yes for prune
        else if(!root->left && !root->right && root->val==1) return false;//false->dont prune
        bool l=prune(root->left), r=prune(root->right);
        if(l)
            root->left=nullptr;
        if(r)
            root->right=nullptr;
        return (l && r && root->val==0);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root->left && !root->right && root->val==0) return NULL;
        else if(!root->left && !root->right && root->val==1) return root;
        else {
            if(prune(root)) return NULL;
            else return root;
        }
    }
};