#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//dfs on node using map that stores visited nodes
//map not needed as an array of n-1 values suffices, but we dont know what the value of n initially is
//doesnt work because interpretation of list of adj nodes is wrong
class Solution {
public:
    Node* dfs(Node* oldroot, unordered_map<int,bool>& visited) {
        Node* newroot=new Node(oldroot->val);
        visited.insert({oldroot->val, true});
        for(auto& node:oldroot->neighbors)  {
            if(visited.find(node->val) == visited.end()){
                newroot->neighbors.push_back(dfs(node, visited));
            }
        }
        return newroot;
    }
    Node* cloneGraph(Node* node) {
        if(!node) {//no nodes in graph
            Node* ans=new Node();
            return ans;
        }
        if(node->neighbors.size() == 0) return node;//only one node in graph
            
        unordered_map<int,bool> visited;
        return dfs(node, visited);
        
    }
};