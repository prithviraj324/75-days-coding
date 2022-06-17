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