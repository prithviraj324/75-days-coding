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
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX); //using LONG_MIN, LONG_MAX to handle edge cases like INT_MIN/INT_MAX
    }
private:
    bool valid(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }
        if (root -> val <= min || root -> val >= max) {
            return false;
        }
        return valid(root -> left, min, root -> val) && valid(root -> right, root -> val, max);
    }
};