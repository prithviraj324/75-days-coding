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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        ans.push_back({root->val});
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* last = root;
        
        while (!q.empty()) {
            vector<int> temp;
            
            int len=q.size();
            for(int i=0;i<len;i++) {
                if(q.front() == NULL) continue;
                else {
                    if(q.front()->left != NULL) {
                        q.push(q.front()->left);
                        temp.push_back(q.front()->left->val);
                    }
                    if(q.front()->right != NULL) {
                        q.push(q.front()->right);
                        temp.push_back(q.front()->right->val);
                    }
                    q.pop();
                }
            }
            if(temp.size() < 1) continue;
            ans.push_back(temp);
        }
        return ans;
    }
};