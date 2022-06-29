#include<bits/stdc++.h>
using namespace std;

class Trie {
    public:
    struct TrieNode{  //making trie struct
        struct TrieNode* child[26];
        bool end;
    };

    TrieNode* root; //creating root for each trie object
    Trie() {
        root = new TrieNode();
    }   //initialize root node in constructor
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c:word) {
            if(cur->child[c-'a'] == NULL)   //if no child has same char, make new child node
                cur->child[c-'a'] = new TrieNode(); //making new child node
            cur = cur->child[c-'a'];    //going to next character for next iteration
        }
        cur->end = true;    //set node as end of word in trie
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(auto c:word) {
            if(cur->child[c-'a'] == NULL) return false;
            cur=cur->child[c-'a'];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c: prefix){
            if(cur->child[c-'a'] == NULL) return false;
            cur = cur->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */