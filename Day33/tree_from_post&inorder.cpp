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
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {//passing by value adds copy time and stack space
        if(preorder.size()==0 || inorder.size()==0) return nullptr;
        
        //preorder[0] = root of tree
        //so the postfix array has left and right subtrees
        //decide which is left and right subtree by using inordere traversal
        //all elements in inorder[0....preorder[0]] are part of the left subtree, as inorder = left,root,right
        //repeat till either array is exhausted
        
        TreeNode* root = new TreeNode(preorder[0]);

        int mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+mid+1), vector<int>(inorder.begin(), inorder.begin() + mid));
        
        root->right = buildTree(vector<int>(preorder.begin()+mid+1, preorder.end()), vector<int>(inorder.begin()+mid+1, inorder.end()));
        
        return root;
    }
};

//optimizing for stack space by passing by reference and passing indices
//TC:O(n2) again but SC:O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  //search from left to right for root
        // find the root (preorder[0]) in inorder[]
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};

//TC :: O(n2) due to searching for root in inorder[].
//this can be mitigated by making a global hashmap

class Solution {
public:
    TreeNode* buildTree(vector<int>& P, vector<int>& I) {
        unordered_map<int, int> M;
        for (int i = 0; i < I.size(); i++)
            M[I[i]] = i;
        return splitTree(P, M, 0, 0, I.size()-1);
    }
    
private:
    TreeNode* splitTree(vector<int>& P, unordered_map<int, int>& M, int pix, int ileft, int iright) {
        int rval = P[pix], imid = M[rval];
        TreeNode* root = new TreeNode(rval);            
        if (imid > ileft)
            root->left = splitTree(P, M, pix+1, ileft, imid-1);
        if (imid < iright)
            root->right = splitTree(P, M, pix+imid-ileft+1, imid+1, iright);
        return root;
    }
};