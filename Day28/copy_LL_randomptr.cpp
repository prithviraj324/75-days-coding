#include<bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//retarded solution i thought of first, couldnt figure out relation between the new to old LL
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* temp = head, *res = new Node(0);  //temp: loop var, res=head of res LL
        Node* copy = res;   //loop var for copy LL
        Node* prev; //using this just to delete excess node created at the end
        unordered_map<Node*, int> old;    //map node to its index
        unordered_map<int, int> rand;    //map indices to random ptr's index, index 0's random ptr is node with index x etc
        unordered_map<int, Node*> newm;    //map indices to newnodes
        int i=0;
            
        while(temp) {
            copy->val = temp->val;  //copy val into copy list
            copy->next = new Node(0);   //initialize next node
            old[temp] = i;    //map old node to its index
            newm[i] = copy;
            temp = temp->next;
            prev = copy;
            copy = copy->next;
            i++;
        }
        old[NULL] = i; //adding last null ptr as it can be random ptr of any node        
        temp=head;  //reset to head
        
        while(head) {
            rand[old[head]] = old[head->random];
            head = head->next;
        }
        
        prev->next = NULL;  //set last node as null bcz its extra
        delete copy;   
        for(int j=0;j<i;j++) {
            newm[j]->random = newm[rand[j]];
        }
        
        return res;
    }
};

//----------------------------------------------------------------
//think
//no need to create new node AND link them
//idea.jpg
//pass 1: allocate space and create new nodes and only copy their values, dont link them yet
//        store a old_node->new_node map
//pass 2: consult map to find new_node of old_node, 
//                  map[old] gives new
//                  map[old]->next = map[old->next]
//                  map[old]->random = map[old->random]

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};

//O(1) space solution by adding a seperate pointer in each node     
//https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1059181/C%2B%2B-or-Three-Pass-or-O(n)-0ms-Beats-100-or-Explanation-(with-example)

class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        
        // STEP 1: PASS 1
        // Creating a copy (except random pointer) of each old node and insert it next to the old node it's copied from.
        // That is, it will create new alternative nodes which are a copy (except random pointer) of its previous node.
        Node* node=head;
        while(node){
            Node* temp=node->next;
            node->next=new Node(node->val);
            node->next->next=temp;
            node=temp;
        }
        
        // STEP 2: PASS 2
        // Now copy the random pointer (if exists) of the old nodes to their copy new nodes.
        node=head;
        while(node){
            if(node->random)
                node->next->random=node->random->next;
            node=node->next->next; // go to next old node
        }
        
        //STEP 3: PASS 3
        // Copy the alternative nodes into "ans" link list using the "helper" pointer along with restoring the old link list.
        Node* ans=new Node(0); // first node is a dummy node
        Node* helper=ans;
    
        while(head){
            // Copy the alternate added nodes from the old linklist
            helper->next=head->next;
            helper=helper->next;
            
            // Restoring the old linklist, by removing the alternative newly added nodes
            head->next=head->next->next;
            head=head->next; // go to next alternate node   
        }
        return ans->next; // Since first node is a dummy node
    }
};