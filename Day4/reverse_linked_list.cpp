#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)
            return head;
        struct ListNode* prev=head;
        struct ListNode* cur=head;
        struct ListNode x;
        x.val=head->val;
        x.next=nullptr;
        struct ListNode* temp=nullptr;
        while(cur->next != nullptr) {
            cur=cur->next;
            prev->next=temp;
            temp=prev;
            prev=cur;
        }
        prev->next=temp;
        return prev;
    }
    /*
    (1,null) {prev initially}
    (2,node1)->(1,null) {node2 is prev}
    (3,node2)->(2,node1)->(1,null) {node3 is prev}
    (4,node3)->(3,node2)->(2,node1)->(1,null) {...}
    ...
    */
};