#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
//bruteforce->check for each node m in list1, whether node n in list2 is the same as m
//O(m*n)
//cant compare pointer values directly, hence use map to calculate hashes for each pointer and the first common pointer is the intersection point
//TC:O(m+n), SC:O(m)    
    ListNode *getIntersectionNode(ListNode *hA, ListNode *hB) {
        unordered_map<ListNode*, int> m;
        while(hA) {
            m[hA]++;
            hA=hA->next;
        }
        while(hB) {
            if(m[hB]>0) return hB;
            hB=hB->next;
        }
        return NULL;
    }
};

/*better solution: length difference
length diff between the lists is only due to len diff in sublists before intersection
once list1* reaches end, switch to head->list2, and same for list2*
basically, -find lengths m and n of lists
           -find (m-n), if(m-n) < 0, move forward |m-n| steps in 2nd list
                        else, move forward |m-n| steps in 1st list
           -this ensures that both head1 and head2 are equidistant from instersection point, now just loop till intersection
*/

class Solution2 {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int m=1,n=1;
        auto ha=headA->next, hb=headB->next;
        while(ha){
            m++;
            ha=ha->next;
        }
        while(hb){
            n++;
            hb=hb->next;
        }//calc m and n
        ha=headA;
        hb=headB;
        int t=abs(m-n);
        if(m<n) {
            while(t!=0){
                hb=hb->next;
                t--;
            }
        }
        else if(m>n) {
            while(t!=0) {
                ha=ha->next;
                t--;
            }
        }//reach equidistant points
        while(ha && hb) {
            if(ha==hb) return ha;
            else {
                ha=ha->next;
                hb=hb->next;
            }
        }
		return NULL;
	}
};