#include<bits/stdc++.h>
using namespace std;
//TLE wildly varies for this question
//Soln1: very close to TLE
class LRUCache {
public:
    class node
    {
        public:
            int key, val;
            node *prev, *next;
            node(int _key,int _val) {
                key=_key;
                val=_val;
            }
    };
    
    node *head=new node(-1,-1); //dummy head
    node *tail=new node(-1,-1); //dummy tail
    
    int cap=0;
    unordered_map<int,node *>ma;
    
    LRUCache(int capacity) {
        
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void deletenode(node *curr) {//delete node from DLL, must always be followed by addNode
        node *prevnode=curr->prev;
        node *nextnode=curr->next;
        
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        
    }
    void addnode(node *curr)  {   //adds node at beginning of DLL, ***right after head*** as it is the MRU
        node *temp=head->next;
        curr->next=temp;
        curr->prev=head;
        
        temp->prev=curr;
        head->next=curr;
        
    }
    int get(int key) {
        if(ma.find(key)!=ma.end())  //if in LL
        {
            node *curr=ma[key]; //get ptr to old pos
            
            int ans=curr->val;  //get value of key
            
            ma.erase(key);  //delete ptr to old node from map
            deletenode(curr);   //delete old node from map
            addnode(curr);      //add new node to make it MRU
            ma[key]=head->next;     //add new entry to map, heaad-> next because ***
            
            return ans;
        }
        return -1;   //not in LL
    }
    
    void put(int key, int value) {
        
        if(ma.find(key)!=ma.end()) {    //if in map, update value, else just add new node at the end
            node *curr=ma[key];
            deletenode(curr);
            ma.erase(key);
        }
        if(ma.size()==cap) {    //size exceeded, pop LRU node i.e node just before tail
            ma.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));   //add a new entry
        ma[key]=head->next;
    }
};

//can also use list instead of a DLL to store MRU and LRU
//only works on servers compiling with specific C++ standards >C++11
//TLE sometimes
class LRUCache {
    public:
    int size;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value

    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if (kv.count(key) == 0) return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if (kv.size() == size && kv.count(key) == 0)
            evict();
        updateLRU(key);
        kv[key] = value;
    }
    
    void updateLRU(int key) {
        if (kv.count(key)) 
            lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};