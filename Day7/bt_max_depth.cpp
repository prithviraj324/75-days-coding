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
    int inorder(TreeNode* root, int depth) {
        if(root==NULL) return depth-1;
        int ld=depth,rd=depth;
        ld=inorder(root->left,depth+1);
        rd=inorder(root->right,depth+1);
        return max(ld,rd);
    }
    int maxDepth(TreeNode* root) {
        int depth=1;
        return inorder(root,depth);
    }
};