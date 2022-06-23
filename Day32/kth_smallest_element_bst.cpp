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
//bruteforce O(n) dfs soln with maxheap holding k smallest values, using pq.top() to prune
class Solution {
public:
    priority_queue<int> pq;
    void dfs(TreeNode* root, int k) {
        if(!root) return;
        pq.push(root->val);
        if(pq.size() > k) pq.pop();
        if(pq.size() == k && root->val > pq.top()) {
            dfs(root->left, k);
        }
        else {
            dfs(root->left, k);
            dfs(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return pq.top();
    }
};
//smarter solution
//in inorder traversal of bst, arr[k-1] is kth smallest element anyways
//TC: O(k), SC: O(k) i.e stack space
class Solution {
public:
    int ans;
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
    
    void inorder(TreeNode* root, int& k) {
        if (!root) return;
        inorder(root->left, k);
        if (--k == 0){
            ans = root->val;
            return;
        } 
        inorder(root->right, k);
    }  
};