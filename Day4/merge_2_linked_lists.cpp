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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode* prev=NULL, *head;
        
        if(!list1)//if either LL is empty
            return list2;
        else if(!list2)
            return list1;
        else {}
        
        if(list1->val <= list2->val) {//set head for merged array
            prev=list1;
            list1=list1->next;
        }
        else {
            prev=list2;
            list2=list2->next;
        }
        
        head=prev;
        while(list1 || list2) {
            if(!list1) {
                prev->next=list2;
                break;
            }
            else if(!list2) {
                prev->next=list1;
                break;
            }
            if(list1->val <= list2->val) {
                prev->next=list1;
                prev=prev->next;
                list1=list1->next;
            }
            else {
                prev->next=list2;
                prev=prev->next;
                list2=list2->next;
            }
        }
        return head;
    }
};