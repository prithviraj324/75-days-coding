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
//after fixing interpretation, realized we need to store copies of node even though they have been visited in adj list
class Solution2 {
public:
//this dfs function doesnt work
    /*Node* dfs(Node* cur, unordered_map<Node*,Node*>& visited) {
        Node* clone=new Node(cur->val);
        visited[cur]=clone;
        for(auto& node:cur->neighbors)  {
            if(visited.find(cur) == visited.end())
                clone->neighbors.push_back(dfs(node, visited));
            else 
                clone->neighbors.push_back(visited[node]);
        }
        return clone;
    }*/
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) //no nodes in graph
            return NULL;
        
        if(node->neighbors.size() == 0) {//only one node in graph
            Node* temp=new Node(node->val);
            return temp;
        }
        unordered_map<Node*,Node*> visited;
        return dfs(node, visited);
        
    }
};