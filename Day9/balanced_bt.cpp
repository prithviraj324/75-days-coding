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
//----------------------------------------------------------------
class Solution {
public:
    bool flag=true;
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        dfs(root);
        return flag;
    }
private:
    int dfs(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=dfs(root->left),rh=dfs(root->right);
        if(max(lh,rh)-min(lh,rh)>1) flag=false;
        return 1+max(lh,rh);
    }
};