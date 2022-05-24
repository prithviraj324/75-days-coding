#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
//-------------------------------
/*
first approach: only leaf nodes can be dead ends bcz we can insert only in subtrees,
now, we check if leafnode.val+1 and leafnode.val-1 exist in tree or not
get and store all leaf nodes in O(n) time and O(n) space, search for +1 and -1 in bst in logn time for n leaf nodes
TC-O(nlogn), SC-O(n)
can eliminate sc by checking neighbours as soon as we hit leaf node
*/
//-------------------------------
/*
next approach:store all nodes in map, store all leaf nodes in another map
for each node in leafnodemap, check if node.val+1 and -1 exist in allnodesmap in O(1) time, n times
TC-O(n),SC-O(n)
*/
//-------------------------------
/*
approach 3: do dfs, all nodes left of root will have val < root.val
hence if any node in left subtree has val=root.val - 1, u cant input to its right
similarly for right subtree
TC:O(n), SC:O(height of tree) bcz of recursive stack space
*/
bool solve(Node* root, int min, int max) {
    if(!root) return false;
    if(min == max) return true;
    return (solve(root->left,min,root->data-1) or solve(root->right,root->data+1,max));
}

bool isDeadEnd(Node* root) {
    return solve(root,1,INT_MAX);
}