//HARD
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    struct compare {
        bool operator()(ListNode* p, ListNode* q) {
            return q->val < p->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return 0;
        if(lists.size() == 1) return lists[0];
        
        ListNode* head = new ListNode(-1);    //dummy first ptr
        //TODO: return head->next as head is dummy
        ListNode* temp = head;
        priority_queue<ListNode*, vector<ListNode*>, compare> minh;
        int emptys=0;
        for(auto n: lists)  {//push all first elements into heap
            if(!n)  emptys++;
            else minh.push(n);
        }
        while(!minh.empty() && minh.top()->val != INT_MAX) {
            ListNode* top = minh.top();
            temp->next = new ListNode(top->val);
            temp=temp->next;
            minh.pop(); //used that headOfLL, saved in 'top'
            top=top->next; //move forward in LL
            if(!top) {  //if list ended, push INT_MAX onto heap
                top=new ListNode(INT_MAX);
                minh.push(top);
            }
            else
                minh.push(top);   // else push next element i.e. new top
        }
        
        return head->next;
    }
};