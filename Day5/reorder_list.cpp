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
//SOLUTION 1: USING STACK
//TC-O(N), SC-O(N)
//----------------------------------------------------------------
class Solution {
public:
    void reorderList(ListNode* head) {
        int i=0;
        stack<ListNode*> st;
        if(!head || !head->next) return;
        
        ListNode* slow=head, *fast=head, *ptr=head,*mid,*temp;//ptr is loop ptr
        while(fast && fast->next) {//slow and fast pointer to reach mid
            slow=slow->next;
            fast=fast->next->next;

        }

        mid=slow;//store mid element in mid
        while (slow) {
            st.push(slow);
            slow=slow->next;
        }

        while(!st.empty()) {
            ListNode* top=st.top();
            
            if(ptr==top) 
                break;
            
            temp=ptr->next;
            ptr->next=top;
            ptr=ptr->next;
            ptr->next=temp;
            ptr=ptr->next;
            st.pop();
        }
        ptr->next=NULL;
    }
};
//----------------------------------------------------------------
//SOLUTION 2: USING 2 POINTER
//TC-O(N), SC-O(1)
//we take 2 sublists, left sublist and right sublist
//get left sublist by [head,slow], right sublist by [slow->next,fast or fast->next] depending whether odd or even elements
//next, we reverse right sublist
//hence we get 2 lists (in place, TC-o(n), sc-o(1))
//now add ele1 from l1 followed by ele2 from l2, l1++,l2++ 
//----------------------------------------------------------------
class Solution2 {
public:
    ListNode* reverse(ListNode* head) {//recursive reverse LL using one ptr
        if (!head || !(head -> next)) {
            return head;
        }
        ListNode* node = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
    void reorderList(ListNode* head) {
        ListNode* slow=head, *fast=head->next,*l1=head,*l2,*temp1,*temp2,*mid,rlist;
        //l1 for left sublist, l2 for right sublist
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        mid=slow;

        l2=reverse(mid->next);//reversed right sublist
        
        while(l1->next && l2) {
            temp1=l1->next;//   saving headless sublists
            temp2=l2->next;//       ""
            l1->next=l2;
            l2->next=temp1;
            l1=temp1;
            l2=temp2;
        }
        l1->next=NULL;
    }
};