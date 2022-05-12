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
//do level order traversal and push last element inserted into a level into ans[]
//----------------------------------------------------------------
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return {};
        ans.push_back(root->val);
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* lastin=root;
        
        while(!q.empty()) {
            int len=q.size();
            for(int i=0;i<len;i++) {
                TreeNode* front=q.front();
                if(front->left) {
                    q.push(front->left);
                    lastin=front->left;
                }
                if(front->right) {
                    q.push(front->right);
                    lastin=front->right;
                }
                q.pop();
            }//for
            ans.push_back(lastin->val);
        }//while
        ans.pop_back();
        return ans;
    }
};