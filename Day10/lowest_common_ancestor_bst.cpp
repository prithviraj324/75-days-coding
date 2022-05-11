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
    bool bsearch(TreeNode* root,int val) {
        while(root!=NULL) {
            if(val==root->val)
                return true;
            else if(val>root->val) 
                root=root->right;
            else 
                root=root->left;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p,q);
        bool l,r;
        l=bsearch(root->left,p->val) || root->val==p->val;
        r=bsearch(root->right,q->val) || root->val==q->val;
        
        if(l&&r) return root;
        else {
            if(root->val > q->val)
                return lowestCommonAncestor(root->left,p,q);
            else 
                return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};
//-------------------------------
//non recursive solution 
//-------------------------------

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            swap(p,q);
        
        while(root) {
            if(p->val > root->val) 
                root=root->right;
            else if(q->val < root->val)
                root=root->left;
            else return root;
        }
        return root;
    }
};