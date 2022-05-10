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
//using bfs to expand each node one by one and check if subRoot is subtree
//its bruteforce, hence tc:O(n), sc:O(n)
//----------------------------------------------------------------
class Solution {
public:
    bool sameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;       //both are null
        
        else if(!p || !q) return false; //one of them is null, hence not same
        
        else if(p->val==q->val)         //both are not null and both have same data
            return (sameTree(p->left,q->left) && sameTree(p->right,q->right));
        
        else return false;              //both are not null, both are diff
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            if(q.front()->val==subRoot->val)
                ans=sameTree(q.front(),subRoot);
            if(ans) return ans;
            if(q.front()->left)
                q.push(q.front()->left);
            if(q.front()->right)
                q.push(q.front()->right);
            q.pop();
        }
        return false;
    }
};
//----------------------------------------------------------------
//better soln, dont use bfs, recursively check for left/right subtree of Root, whether subRoot is subtree of root subt
//Tc:O(n),sc:O(n) bcz stack has n calls in worst case of root subtree
//----------------------------------------------------------------
class Solution2 {
public:
    bool sameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;       //both are null
        
        else if(!p || !q) return false; //one of them is null, hence not same
        
        else if(p->val==q->val)         //both are not null and both have same data
            return (sameTree(p->left,q->left) && sameTree(p->right,q->right));
        
        else return false;              //both are not null, both are diff
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        
        if (sameTree(root,subRoot)) return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};