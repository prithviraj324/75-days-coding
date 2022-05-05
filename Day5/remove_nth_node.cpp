#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//----------------------------------------------------------------
//BRUTE FORCE SOLUTION 
//TC-O(N),SC-O(1)\
//linearly find size first, then go to index just before node to delete and then delete it
//----------------------------------------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head, *temp;
        int size=1;
        
        while(ptr->next) {//get size of LL
            ptr=ptr->next;
            size++;
        }
        ptr=head;
        
        if(n==size){//if deleting first element
            ptr=ptr->next;
            return ptr;
        }
        
        size-=n;
        while(size>1) {//go to position before node to be deleted
            ptr=ptr->next;
            size--;
        }
        temp=ptr->next->next;
        ptr->next=temp;
        return head;
    }
};
//----------------------------------------------------------------
//SOLUTION2:
//left and right pointers, left pointer points before head, right pointer points to n'th element
//this is so that at the end, r points to last element and l points to node before the node to be deleted
//tc-o(n) but much faster as its not 2n iterations as before
//----------------------------------------------------------------
class Solution2 {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return NULL;
        struct ListNode* l=new ListNode(0,head);
        ListNode* r=head,*temp;
        
        for(int i=1;i<n;i++)    //move right ptr to posn n
            r=r->next;
        
        if(!r->next)    //if n=size(LL) ie delete 1st element
            return head->next;
        
        while(r->next){
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        return head;
    }
};