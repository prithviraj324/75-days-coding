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
//-------------------------------------------------------------
//naive recursive solution
//tc-O(n), we go through all nodes in bt
//sc-O(n): each node in recursive call stack
//---------------------------------------------------------------- 
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
//----------------------------------------------------------------
//using level order traversal, you can do it iteratively 
//tc-O(n): going through all nodes in the tree
//sc-O(logn)->O(n): since we can have either max logn nodes in queue(in case of balanced bt) or n nodes (in case of unbalanced bt)
//----------------------------------------------------------------


//----------------------------------------------------------------
//another solution is iterative dfs using preorder traversal and stack
//tc-O(n): same as before
//sc-O(n): simulating recursive callstack as in first Solution
//----------------------------------------------------------------