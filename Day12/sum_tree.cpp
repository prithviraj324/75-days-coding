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
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        // Your code here
        if(sum(root) != INT_MIN)
            return true;
        
        return false;
    }
    int sum(Node* root) {
        if(!root) return 0;
        if(!root->left && !root->right) 
            return root->data;
        
        int l = sum(root->left),r = sum(root->right);
        if(root->data != (l+r)) return INT_MIN;
        return l+r+root->data;
    }
};