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
//-------------------------------
//naive solution:
//at each node, calculate left subtree height lh and right subtree height rh and right subtree
//at each node, max diameter=(lh(node)+rh(node)+1), this +1 is because of t\longest path thru node also
//tc-O(n)*O(n) because at each node, we calculate left&right subtree height which is O(n) in worst case (skewed tree)
//sc-O(1)
//----------------------------------------------------------------


//----------------------------------------------------------------
//optimized solution:
//

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        rec(root, d);
        return d;
    }
    
    int rec(TreeNode* root, int &d) {
        if(root == NULL) return 0;
        int ld = rec(root->left, d);
        int rd = rec(root->right, d);
        d=max(d,ld+rd);
        return max(ld,rd)+1;
    }
};